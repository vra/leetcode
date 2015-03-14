class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;		//the while loop times
		    int sum = 0;		//the over all '1' in binary format of n

		    unsigned int tmp_old = n;	
		    unsigned int tmp_new = n;
		    int tail = 0;		//除后的余数

		    while ( count < 32 && pow(2, count) + tail <= n)
	  	  {
			      tmp_new = tmp_old / 2;
			      tail = tmp_old - tmp_new * 2;

			      if (tail == 1)
		  	    {
				      sum++;
			       }

			    tmp_old = tmp_new;
			    count++;
		  }

		  return sum;
        
    }
};
