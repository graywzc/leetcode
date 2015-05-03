class Solution {
public:
    string simplifyPath(string path) {
        string res;
        if(path.size() == 0)
            return res;
        stack<string> hp;                
        bool isroot = false;
        int i = 0;
        if(path[i] == '/')
            isroot = true;
        string temp;
        int numDot = 0;
        while(i < path.size())
        {
            if(path[i] == '/')
            {
                if(numDot == 2)
                {
                    if(hp.size() != 0)
                        hp.pop();  
                    numDot = 0;
                }
                else if(numDot == 1)
                {
                    numDot = 0; 
                }
                else if(temp.size()>0)
                {
                    hp.push(temp); 
                    temp.clear();
                }
            }
            else if(path[i] == '.')
            {
                if(temp.size()>0)
                    temp+="."; 
                else
                    numDot++; 
            }
            else
            {
                while(numDot>0)
                {
                    temp+="."; 
                    numDot--;
                }
                temp+=path[i];
            }
            i++; 
        }

        if(numDot>2)
        {
            while(numDot>0)
            {
                temp+="."; 
                numDot--;
            }
        }
        else if(numDot == 2)
        {
            if(hp.size()>0)
                hp.pop();
        }
        numDot = 0;

        if(temp.size()>0)
            hp.push(temp);

        while(hp.size()>0)
        {
            reverse(hp.top().begin(), hp.top().end());          
            res+=hp.top();
            hp.pop();
            res+="/";
        }
        if(res.size()>0)
        {
            if(!isroot)
                res.pop_back();
            reverse(res.begin(), res.end());
        }
        else
        {
            if(isroot) 
                res+="/";
        }

        return res;
    }
};
