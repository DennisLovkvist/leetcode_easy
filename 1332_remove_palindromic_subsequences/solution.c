bool IsPalindrome(char * s, int left, int right)
{
    while(left < right)
    {
        if(s[left] == '0')
        {
            left ++;
        }
        else if(s[right] == '0')
        {
            right --;
        }
        else
        {
            if(s[left] != s[right])
            {
                return false;
            } 
            left++;
            right--;
        }
    }
    return true;
}
int removePalindromeSub(char * s)
{
    int len = strlen(s);
    
    int remainder = len;
    int steps = 0;
    
    int left = 0;
    int right = len-1;

    int largest = len-1;
    
    if(len == 1)
    {
        return 1;
    }
    if(IsPalindrome(s,left,right))
    {
        return 1;
    }   
    while(remainder > 0)
    {   
        if(IsPalindrome(s,left,right))
        {
            memset(s + (left*sizeof(char)),'0',largest);        
            remainder -= largest;
            steps ++;
        }
        else if(IsPalindrome(s,left,right-1))
        {
            memset(s + (left*sizeof(char)),'0',largest-1);        
            remainder -= largest;
            steps ++;
        }
        else if(IsPalindrome(s,left+1,right))
        {
            memset(s + ((left+1)*sizeof(char)),'0',largest-1);
            remainder -= largest;
            steps ++;
        }
        else
        {
            left++;
            right--;
            largest--;
        }
    }
       
    return steps;
}
