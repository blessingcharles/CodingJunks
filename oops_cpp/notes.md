## General

#### Storage Classes

  Storage Class 	Keyword 	Lifetime 	    Visibility 	 Initial Value
  
1. Automatic 	    auto 	    Function Block 	Local 	     Garbage
2. Register 	    register 	Function Block 	Local 	     Garbage
3. Mutable 	        mutable 	Class       	Local 	     Garbage
4. External 	    extern   	Whole Program 	Global 	     Zero
5. Static 	        static  	Whole Program 	Local 	     Zero


- namespaces : to avoid naming conflicts , in c people did it by appending their library prefix to 
functions eg : Loginit() but in cpp we can use namespace

```cpp
namespace Log{
  void init(){
  }
}
```

- const : cannot modify value or assignments
```cpp
const int* const a = new int ;

*a = 5 ; // it will fail due to const int* a  === int const* a

a = &b ;  // it will fail due to int* const a
```


- smart ptrs : automatically call new and delete when goes out of scope
1. unique_ptr : automatically calls delete when go out of scope , dangerous to share
2. shared_ptr : can we share because deletion is based on reference counting
3. weak_ptr  : assigning shared_ptr to it , doesn't increase ref count

- dangling ptr
```cpp
int * func(){
  int *a = new int ; return a ;
}
int *bb = func() ;
```

- void ptr : A generic ptr , we cannot perform reading on it without typecase  usecase : malloc returns it

- Copy Constructor : copy one object from other

1. Default one : produces shallow copy
2. user defined 

