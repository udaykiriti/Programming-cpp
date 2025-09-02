# Step 1: Import libraries
import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
from sklearn.preprocessing import StandardScaler
import joblib
import matplotlib.pyplot as plt
import seaborn as sns

# Step 2: Load dataset
# You can replace this with your own CSV like: pd.read_csv('your_data.csv')
from sklearn.datasets import load_iris
iris = load_iris()
df = pd.DataFrame(iris.data, columns=iris.feature_names)
df['target'] = iris.target

# Step 3: Define features and target
X = df.drop('target', axis=1)
y = df['target']

# Step 4: Preprocessing (optional: scaling for visualization/tuning)
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# Step 5: Train/Test split
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.3, random_state=42, stratify=y)

# Step 6: Define Random Forest model with hyperparameter tuning
param_grid = {
    'n_estimators': [100, 200],
    'max_depth': [None, 5, 10],
    'min_samples_split': [2, 5],
    'min_samples_leaf': [1, 2],
    'bootstrap': [True, False]
}

grid_search = GridSearchCV(RandomForestClassifier(random_state=42),
                           param_grid,
                           cv=5,
                           n_jobs=-1,
                           verbose=1)

grid_search.fit(X_train, y_train)

# Step 7: Best model
best_model = grid_search.best_estimator_
print("Best Parameters:", grid_search.best_params_)

# Step 8: Evaluation
y_pred = best_model.predict(X_test)

print("\nClassification Report:")
print(classification_report(y_test, y_pred))

print("\nConfusion Matrix:")
conf_matrix = confusion_matrix(y_test, y_pred)
sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='Blues')
plt.title("Confusion Matrix")
plt.xlabel("Predicted")
plt.ylabel("Actual")
plt.show()

print("\nAccuracy Score:", accuracy_score(y_test, y_pred))

# Step 9: Feature Importance
importances = best_model.feature_importances_
features = X.columns
indices = np.argsort(importances)

plt.figure(figsize=(8, 6))
plt.title('Feature Importances')
plt.barh(range(len(indices)), importances[indices], color='green', align='center')
plt.yticks(range(len(indices)), [features[i] for i in indices])
plt.xlabel('Relative Importance')
plt.show()

# Step 10: Save the model
joblib.dump(best_model, 'random_forest_model.pkl')
joblib.dump(scaler, 'scaler.pkl')

# Step 11: Load and predict later
# model = joblib.load('random_forest_model.pkl')
# scaler = joblib.load('scaler.pkl')
# sample = scaler.transform([[5.1, 3.5, 1.4, 0.2]])
# prediction = model.predict(sample)
# print("Predicted class:", iris.target_names[prediction[0]])
