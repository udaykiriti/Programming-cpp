#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <map>

using namespace std;

struct TreeNode {
    int feature_index = -1;
    double threshold = 0;
    int prediction = -1;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class DecisionTree {
    int max_depth;
    int min_size;
    int num_features;
public:
    DecisionTree(int max_depth = 10, int min_size = 1, int num_features = 0)
        : max_depth(max_depth), min_size(min_size), num_features(num_features) {}

    TreeNode* build_tree(const vector<vector<double>>& X, const vector<int>& y) {
        return split(X, y, 0);
    }

    int predict(TreeNode* node, const vector<double>& x) {
        if (node->prediction != -1) return node->prediction;
        if (x[node->feature_index] < node->threshold)
            return predict(node->left, x);
        else
            return predict(node->right, x);
    }

private:
    double gini_index(const vector<vector<double>>& groups, const vector<vector<int>>& classes) {
        int n_instances = 0;
        for (auto& group : groups) n_instances += group.size();

        double gini = 0.0;
        for (auto& group : groups) {
            int size = group.size();
            if (size == 0) continue;
            double score = 0.0;
            map<int, int> class_counts;
            for (int idx : group) class_counts[idx]++;
            for (auto& c : classes) {
                double p = (class_counts[c[0]] ? (double)class_counts[c[0]] / size : 0);
                score += p * p;
            }
            gini += (1.0 - score) * ((double)size / n_instances);
        }
        return gini;
    }

    pair<vector<int>, vector<int>> test_split(int index, double threshold,
        const vector<vector<double>>& X) {
        vector<int> left, right;
        for (int i = 0; i < (int)X.size(); i++) {
            if (X[i][index] < threshold) left.push_back(i);
            else right.push_back(i);
        }
        return {left, right};
    }

    pair<int, double> get_split(const vector<vector<double>>& X, const vector<int>& y) {
        vector<int> feature_indices = random_features(X[0].size(), num_features);
        vector<int> classes = unique_classes(y);

        double best_gini = 1e9;
        int best_index = -1;
        double best_thresh = 0;

        for (int index : feature_indices) {
            vector<double> values;
            for (auto& row : X) values.push_back(row[index]);
            sort(values.begin(), values.end());

            for (size_t i = 1; i < values.size(); i++) {
                double threshold = (values[i - 1] + values[i]) / 2;

                auto groups = test_split(index, threshold, X);
                vector<vector<double>> group_vectors = { {}, {} };
                vector<vector<int>> group_classes = { {}, {} };
                for (int idx : groups.first) {
                    group_vectors[0].push_back(0); // placeholder
                    group_classes[0].push_back(y[idx]);
                }
                for (int idx : groups.second) {
                    group_vectors[1].push_back(0);
                    group_classes[1].push_back(y[idx]);
                }

                double gini = gini_index(group_vectors, group_classes);
                if (gini < best_gini) {
                    best_gini = gini;
                    best_index = index;
                    best_thresh = threshold;
                }
            }
        }
        return {best_index, best_thresh};
    }

    TreeNode* split(const vector<vector<double>>& X, const vector<int>& y, int depth) {
        if (y.empty()) return nullptr;
        if (all_same(y)) {
            TreeNode* leaf = new TreeNode();
            leaf->prediction = y[0];
            return leaf;
        }
        if (depth >= max_depth || (int)y.size() <= min_size) {
            TreeNode* leaf = new TreeNode();
            leaf->prediction = majority_class(y);
            return leaf;
        }

        auto [index, threshold] = get_split(X, y);
        if (index == -1) {
            TreeNode* leaf = new TreeNode();
            leaf->prediction = majority_class(y);
            return leaf;
        }

        auto groups = test_split(index, threshold, X);
        vector<vector<double>> leftX, rightX;
        vector<int> leftY, rightY;
        for (int i : groups.first) {
            leftX.push_back(X[i]);
            leftY.push_back(y[i]);
        }
        for (int i : groups.second) {
            rightX.push_back(X[i]);
            rightY.push_back(y[i]);
        }

        TreeNode* node = new TreeNode();
        node->feature_index = index;
        node->threshold = threshold;
        node->left = split(leftX, leftY, depth + 1);
        node->right = split(rightX, rightY, depth + 1);
        return node;
    }

    bool all_same(const vector<int>& y) {
        for (size_t i = 1; i < y.size(); i++) {
            if (y[i] != y[0]) return false;
        }
        return true;
    }

    int majority_class(const vector<int>& y) {
        map<int, int> counts;
        for (int v : y) counts[v]++;
        int max_count = 0, majority = y[0];
        for (auto& p : counts) {
            if (p.second > max_count) {
                max_count = p.second;
                majority = p.first;
            }
        }
        return majority;
    }

    vector<int> unique_classes(const vector<int>& y) {
        vector<int> classes = y;
        sort(classes.begin(), classes.end());
        classes.erase(unique(classes.begin(), classes.end()), classes.end());
        vector<vector<int>> res;
        for (int c : classes) res.push_back({c});
        vector<int> flat;
        for (auto& v : res) flat.push_back(v[0]);
        return flat;
    }

    vector<int> random_features(int total, int n) {
        vector<int> features(total);
        for (int i = 0; i < total; i++) features[i] = i;
        random_device rd;
        mt19937 g(rd());
        shuffle(features.begin(), features.end(), g);
        features.resize(n);
        return features;
    }
};

class RandomForest {
    vector<DecisionTree> trees;
    vector<TreeNode*> roots;
    int n_trees;
    int max_depth;
    int min_size;
    int n_features;
public:
    RandomForest(int n_trees = 10, int max_depth = 10, int min_size = 1)
        : n_trees(n_trees), max_depth(max_depth), min_size(min_size) {}

    void fit(const vector<vector<double>>& X, const vector<int>& y) {
        int n_features_total = X[0].size();
        n_features = sqrt(n_features_total);
        trees.clear();
        roots.clear();

        for (int i = 0; i < n_trees; i++) {
            vector<vector<double>> sampleX;
            vector<int> sampleY;
            bootstrap_sample(X, y, sampleX, sampleY);

            DecisionTree tree(max_depth, min_size, n_features);
            trees.push_back(tree);
            roots.push_back(trees.back().build_tree(sampleX, sampleY));
        }
    }

    int predict(const vector<double>& x) {
        map<int, int> votes;
        for (auto root : roots) {
            int pred = predict_tree(root, x);
            votes[pred]++;
        }
        int majority_class = -1;
        int max_votes = 0;
        for (auto& v : votes) {
            if (v.second > max_votes) {
                max_votes = v.second;
                majority_class = v.first;
            }
        }
        return majority_class;
    }

private:
    void bootstrap_sample(const vector<vector<double>>& X, const vector<int>& y,
                          vector<vector<double>>& sampleX, vector<int>& sampleY) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, X.size() - 1);
        for (int i = 0; i < (int)X.size(); i++) {
            int idx = dis(gen);
            sampleX.push_back(X[idx]);
            sampleY.push_back(y[idx]);
        }
    }

    int predict_tree(TreeNode* node, const vector<double>& x) {
        if (node->prediction != -1) return node->prediction;
        if (x[node->feature_index] < node->threshold)
            return predict_tree(node->left, x);
        else
            return predict_tree(node->right, x);
    }
};

int main() {
    vector<vector<double>> X = {
        {2.771244718, 1.784783929},
        {1.728571309, 1.169761413},
        {3.678319846, 2.81281357},
        {3.961043357, 2.61995032},
        {2.999208922, 2.209014212},
        {7.497545867, 3.162953546},
        {9.00220326, 3.339047188},
        {7.444542326, 0.476683375},
        {10.12493903, 3.234550982},
        {6.642287351, 3.319983761}
    };

    vector<int> y = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};

    RandomForest rf(5, 5);
    rf.fit(X, y);

    vector<double> test_point = {3.0, 2.0};
    cout << "Prediction for {3.0, 2.0} : " << rf.predict(test_point) << endl;

    return 0;
}
