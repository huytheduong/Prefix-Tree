//this program added and modified the two funtion
#include "prefixtree.h"
#include <cctype>
#include <string>
#include <iostream>
using namespace std;
void PrefixTree::addWord(const string& str)
{
    if(str.empty()) //if string empyty then return
        return;
    
    PrefixTreeNode* current = root; //start from the root
    for(size_t i=0; i<str.length(); i++)
    {
        int find = tolower(str[i]) - 'a';//find the postion of the char in string
        if(!current->link[find])//if not found then add char as new node
        {
            current->addChild(str[i]);
        }
        current = current->link[find];//point to node just created
    }
    current->setFinal(true);//set final if end word
}

bool PrefixTree::contains(const string& str)
{
    if(str.empty()) 
        return false;

    PrefixTreeNode* current = root; //start at the beginning of the node
    for(size_t i=0; i<str.length(); i++) 
    {
        current = current->getChild(str[i]);//check if char exist
        if(current == nullptr)//if not return false
            return false; 
    }

    
    if(current->isFinal())
        return true; 
    else
        return false; 
}

bool PrefixTree::isAllLetters(const string& str) const
{
  for (int i = 0; i < str.size(); i++)
    if (!isalpha(str[i]))
      return false;
  return true;
}

PrefixTree::PrefixTree()
{
  root = new PrefixTreeNode();
  root->final = false;
}

PrefixTree::PrefixTree(const PrefixTree& copy)
{
  root = new PrefixTreeNode(*copy.root);
}

const PrefixTree& PrefixTree::operator=(const PrefixTree& rhs)
{
  delete root;
  root = new PrefixTreeNode(*rhs.root);
  return rhs;
}

PrefixTree::~PrefixTree()
{
  delete root;
}

PrefixTreeNode::PrefixTreeNode()
{
  c = '\0';
  final = false;
  for (int i = 0; i < ALPHABET_SIZE; i++)
    link[i] = nullptr;
}

PrefixTreeNode::PrefixTreeNode(const PrefixTreeNode& copy)
{
  c = copy.c;
  final = copy.final;
  for (int i = 0; i < ALPHABET_SIZE; i++)
    if (copy.link[i] == nullptr)
      link[i] = nullptr;
    else
      link[i] = new PrefixTreeNode(*copy.link[i]);
}

const PrefixTreeNode& PrefixTreeNode::operator=(const PrefixTreeNode& rhs)
{
  c = rhs.c;
  final = rhs.final;
  for (int i = 0; i < ALPHABET_SIZE; i++)
  {
    delete link[i];
    if (rhs.link[i] == nullptr)
      link[i] = nullptr;
    else
      link[i] = new PrefixTreeNode(*rhs.link[i]);
  }
  return rhs;
}

PrefixTreeNode* PrefixTreeNode::getChild(char c)
{
  if (isalpha(c))
    return link[tolower(c)-'a'];
  else
    return nullptr;
}

const PrefixTreeNode* PrefixTreeNode::getChild(char c) const
{
  if (isalpha(c))
    return link[tolower(c)-'a'];
  else
    return nullptr;
}

void PrefixTreeNode::addChild(char c)
{
  if (isalpha(c))
  {
    link[tolower(c)-'a'] = new PrefixTreeNode();
    link[tolower(c)-'a']->c = tolower(c);
  }
}

void PrefixTreeNode::deleteChild(char c)
{
  if (isalpha(c))
  {
    delete link[tolower(c)-'a'];
    link[tolower(c)-'a'] = nullptr;
  }
}

PrefixTreeNode::~PrefixTreeNode()
{
  for (int i = 0; i < ALPHABET_SIZE; i++)
    delete link[i];
}


ostream& operator<<(ostream& out, const PrefixTree& pt)
{
  return out << *pt.getRoot();
}

ostream& operator<<(ostream& out, const PrefixTreeNode& node)
{
  //Count the number of children
  int count = 0;
  for (char c = 'a'; c < 'a' + ALPHABET_SIZE; c++)
    if (node.getChild(c) != nullptr)
      count++;

  //Print our character
  if (node.getChar() != '\0')
    if (node.isFinal())
      out << static_cast<char>(toupper(node.getChar()));
    else
      out << node.getChar();
  
  //Print children
  if (count > 1)
    out << '(';

  int t = count;
  for (char c = 'a'; c < 'a' + ALPHABET_SIZE; c++)
    if (node.getChild(c) != nullptr)
    {
      out << *node.getChild(c);
      if (--t) out << ',';
    }

  if (count > 1)
    out << ')';
  
  return out;
}
