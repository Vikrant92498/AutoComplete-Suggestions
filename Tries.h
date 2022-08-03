#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char letter;
    TrieNode **nextLetter;
    bool isEnd;
    TrieNode(char c){
        letter = c;
        nextLetter = new TrieNode* [26];
        for(int i=0;i<26;i++){
            nextLetter[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie{
    TrieNode *root;
    void insertPrivate(TrieNode *root , string word){
        if(word.length()==0){
            root->isEnd=true;
            return ;
        }
        else if(root->nextLetter[word[0]-'a'] !=NULL){
            insertPrivate(root->nextLetter[word[0]-'a'],word.substr(1));
            return;
        }
        
        root->nextLetter[word[0]-'a'] = new TrieNode(word[0]);
        insertPrivate(root->nextLetter[word[0]-'a'],word.substr(1));
        return;
    }
    void dfs(struct TrieNode* root,string currPrefix,vector<string> &possibleWord){
        if (root->isEnd){
            possibleWord.push_back(currPrefix);
        }
        for (int i = 0; i < 26; i++){
            if (root->nextLetter[i]) {
                char child = 'a' + i;
                dfs(root->nextLetter[i],currPrefix + child,possibleWord);
            }
        }
}
 
    void search(TrieNode* root, const string keyword,vector<string> &possibleWord){
        TrieNode* pCrawl = root;
        for (char c : keyword) {
            int ind = c-'a';
            if (!pCrawl->nextLetter[ind])
                return ;
            pCrawl = pCrawl->nextLetter[ind];
    }
    if (pCrawl->isEnd) {
        possibleWord.push_back(keyword);
        return ;
    }
    dfs(pCrawl, keyword,possibleWord);
    return ;
}
    public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insert(string word){
        insertPrivate(root,word);
    }
    vector<string> autocomplete(string keyword){
        vector<string> possibleWords;
        search(root,keyword,possibleWords);
        return possibleWords;
    }
};
