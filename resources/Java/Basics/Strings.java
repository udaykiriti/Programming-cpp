/*
 But in java string is a class used to create String object,
 String is an Object that represents a sequence of characters
 String invetible in change(cannot be changed)
 There are 2 ways to create String object:
 1.By string literal
 2.By new keyword
 
*/

/* 
1) String literal
it is created by " "
ex: String s="Welcome";

*/

public class Strings{
    public static void main(String[] args) {
        /*
        String str1 = "KL U ";
        String str2 = "University";
        String str3 = "KLU";
        String str4 = new String ("University");
        String str5 = new String ("CSE");
        System.out.println(20+30+ " KLU "+"UNI "+20+30);
        System.out.println(str1.length());
        System.out.println(str1.charAt(3));
        // SubString Methods 
        System.out.println(str2.substring(2));
        System.out.println(str2.substring(1, 5));
        System.out.println(str2.subSequence(1, 5));
        */
        //string buffer
        // It is similar lo string ,but it can chnage the values
        StringBuffer sb = new StringBuffer("KLU");
        System.out.println(sb.append(" University"));

    }
}