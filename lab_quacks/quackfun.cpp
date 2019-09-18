/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 * stacks and queues portion of the lab.
 */
namespace QuackFun {

/**
 * Sums items in a stack.
 *
 * **Hint**: think recursively!
 *
 * @note You may modify the stack as long as you restore it to its original
 * values.
 *
 * @note You may use only two local variables of type T in your function.
 * Note that this function is templatized on the stack's type, so stacks of
 * objects overloading the + operator can be summed.
 *
 * @note We are using the Standard Template Library (STL) stack in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param s A stack holding values to sum.
 * @return  The sum of all the elements in the stack, leaving the original
 *          stack in the same state (unchanged).
 */
template <typename T>
T sum(stack<T>& s)
{

    // Your code here{
    if(s.empty()==true){
    return T(); 
    }
	// stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
    T item=s.top();
    s.pop();

    T total=sum(s);

    s.push(item);

    return item+total;
}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets.
 * A string will consist of square bracket characters, [, ], and other
 * characters. This function will return true if and only if the square bracket
 * characters in the given string are balanced. For this to be true, all
 * brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is
 * balanced, "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is
 * balanced.
 *
 * For this function, you may only create a single local variable of type
 * `stack<char>`! No other stack or queue local objects may be declared. Note
 * that you may still declare and use other local variables of primitive types.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return      Whether the input string had balanced brackets
 */ 
bool isBalanced(queue<char> input)
{
    stack<char> checker;
    
    while(input.empty()!= true){

			char character=input.front();
			if(character=='['){
				checker.push('[');

			} else if(character==']'){
					if(checker.empty()==true){
						return false;
					}	
					else{
						checker.pop();
					}

			}
			input.pop();

		}
    
    // @TODO: 
    //
    if(checker.empty()==false){
			return false;

    }
    return true;
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 *
 * **Hint**: You'll want to make a local stack variable.
 *
 * @note Any "leftover" numbers should be handled as if their block was
 * complete.
 *
 * @note We are using the Standard Template Library (STL) queue in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param q A queue of items to be scrambled
 */
template <typename T>
void scramble(queue<T>& q)
{
    stack<T> s;
    queue<T> q2;
 
   int i=1;
    // Your code here
    while(q.empty()==false){
			if(i%2==1){
				for(int j=0;j<i;j++){
					if(q.empty()==true){
						q=q2;
						return;
					}
					q2.push(q.front());
					q.pop();
				 }
        }else{
					for(int j=0;j<i;j++){
						if(q.empty()==true){
							break;
						}
						s.push(q.front());
						q.pop();
					}
																	    }
					while(s.empty()==false){
						q2.push(s.top());
						s.pop();	
					}

	        i++;

     }
	
    q=q2;   

    
}

/**	
 * Checks if the parameter stack and queue are the same. A stack and a queue
 * are considered to the "the same" if they contain only elements of exactly
 * the same values in exactly the same order.
 *
 * @note You may assume the stack and queue contain the same number of items!
 *
 * @note The back of the queue corresponds to the top of the stack!
 *
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 *
 * @param s The stack to compare
 * @param q The queue to compare
 * @return  true if the stack and the queue are the same; false otherwise
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{
    
	
		 bool retval = true; // optional
     T temp1; // rename me
		 T temp2; // rename :)

		 if(s.size()==1){
			temp1=s.top();
			temp2=q.front();
			q.pop();
			q.push(temp2);


			if(temp1==temp2){
				return true;
			} else{
				return false;
			}

		}


    // Your code here
		temp1=s.top();
		s.pop();

		retval=verifySame(s,q);
		retval= retval &&(temp1==q.front());

		temp2=q.front();
		q.pop();
		q.push(temp2);

		s.push(temp1);


    return retval;
}

}
