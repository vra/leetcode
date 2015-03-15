class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> digital;	//保存每位上的数字

	      unsigned int tmp_new = n;
	      unsigned int tmp_old = n;
	      int tail = 0;

	      for (int i = 0; i < 32; i++)
	      {
		        tmp_new = tmp_old /2;
		        tail = tmp_old - (tmp_new * 2);

		        digital.push_back(tail);

		        tmp_old = tmp_new;
	      }

	      unsigned int result = 0;

	      for (int i = 0; i < digital.size(); i++)
	      {
		        result += digital[i] * pow(2, 31 - i);
  	    }
	
	      return result;
        
    }
};

// someone's neat answer
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
         unsigned int ret=0;
        int flag=1;
       // while(n)
        for(int i=0;i<32;i++)//1
        {
            flag=1;
            flag=flag&n;  //0
            n=n>>1;  //0
            ret=ret<<1; //10
            ret=ret|flag;//10
        }
        return ret;
    }
};
