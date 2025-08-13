/*
 Excetion is an abnormal Condition That Arises in a Code sequence at runtime
 Exception is a runtime error
 We use it by using some keywords:
 try,catch,throw,throws,finally
 if an exception occurs within the try block,it is thrown

*/
/*
// WAP for ArithemeticException
public class ExceptionHandling{
    public static void main(String[] args) {
        int a=20,b=0,c;
        try{
            c=a/b;
        }catch(ArithmeticException e){
            System.out.println("division by Zero");
        }finally{
            c=a/b;
            System.out.println("value ofc = "+c);
        }
    }
}
*/
public class ExceptionHandling{
    public static void main(String[] args) {
        try {
            int sum=10;
            for(int i=-1;i<3;++i)
                sum=(sum/i);
        } catch (ArithmeticException e) {
            System.out.println("0");
        }
        System.out.println(sum);
    }
}