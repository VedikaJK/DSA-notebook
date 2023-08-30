// Time Complexity : O(sumOfWordLengths) ...  for 1 search operation it will be O(wordLength) 
// Space Complexity : O(sumOfWordLengths)

class Trie {
public:

    // define trie node with kids array and isEndOfWord bool flag
    struct trieNode{
        vector<trieNode*> kids;
        bool isEndOfWord;

        trieNode(){
            kids = vector<trieNode*> (26,nullptr);
            isEndOfWord = false;
        }
    };

    // root of Trie
    trieNode* root;

    // constructor to initialise root
    Trie() {
        root = new trieNode();         
    }
    
    // insert word to Trie 
    void insert(string word) {
        trieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            if(curr->kids[idx] == nullptr){
                curr->kids[idx] = new trieNode();
            }
            curr = curr->kids[idx];
        }
        curr->isEndOfWord = true;
    }
    
    // search word in Trie
    bool search(string word) {
        trieNode* curr = root;

        for(int i=0; i< word.size(); i++){
            int idx = word[i]-'a';
            if(curr->kids[idx]==nullptr){
                return false;
            }
            curr = curr->kids[idx];
        }
        return curr->isEndOfWord;
    }
    
    // see if there is any word with given prefix
    bool startsWith(string prefix) {
        trieNode* curr = root;

        for(int i=0; i< prefix.size(); i++){
            int idx = prefix[i]-'a';
            if(curr->kids[idx]==nullptr){
                return false;
            }
            curr = curr->kids[idx];
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
