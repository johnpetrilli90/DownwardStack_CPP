# DownwardStack_CPP
Downward LIFO stack template class. Allows a stack of up to 1000 values, but this can be modified by adjusting the #define CAP value. The downward stack pushes values onto to an array starting at [CAP-1]. When the stack is full it will be at array index 0. Used unique_ptr to write a function that will reverse the stack order.
