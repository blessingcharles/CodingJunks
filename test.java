import java.util.* ;

class A{
    A(){
       System.out.println("A");
    }
    void fun(){
        //Do nothing
    }
 }
 class B extends A{
    B(){
       System.out.println("B");
    }
    B(String s){
       System.out.println("C");
    }
 }
 public class test{
    public static void main(String []args){
       B b=new B();
       B c=new B("Hello");
    }
 }
 