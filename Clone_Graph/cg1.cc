/**
 * Definition for undirected graph.
 */ 
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };
class Solution {
public:
    static UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)
            return NULL;

        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> ndmap;
        queue<UndirectedGraphNode *> q;
        UndirectedGraphNode * copy = new UndirectedGraphNode(node->label);
        q.push(node);
        ndmap[node] = copy;

        while(q.size()>0)
        {
            UndirectedGraphNode * vert = q.front(); 
            q.pop();

            for(int i = 0; i < vert->neighbors.size(); i++)
            {
                UndirectedGraphNode *nb = vert->neighbors[i];  

                if(ndmap.find(nb)==ndmap.end())
                {
                    q.push(nb);

                    UndirectedGraphNode * nbcopy = new UndirectedGraphNode(nb->label);     
                    ndmap[vert]->neighbors.push_back(nbcopy);
                    ndmap[nb] = nbcopy;
                }
                else
                {
                    ndmap[vert]->neighbors.push_back(ndmap[nb]); 
                }
            }
        }

        return copy;
        
    }
};

int main()
{
    UndirectedGraphNode *node = new UndirectedGraphNode(0);
    UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
    
    node->neighbors.push_back(node1);
    node->neighbors.push_back(node);

    node1->neighbors.push_back(node);
    

     
    UndirectedGraphNode *copy = Solution::cloneGraph(node);
}
