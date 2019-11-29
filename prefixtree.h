#ifndef __PREFIX_TREE_H
#define __PREFIX_TREE_H

#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

class PrefixTreeNode;

/*
  Prefix tree
  Stores a collection of strings as a tree
 */
class PrefixTree
{
private:
  PrefixTreeNode* root;
public:
  //Constructs an empty prefix tree
  PrefixTree();
  //Copy constructor
  PrefixTree(const PrefixTree&);
  //Copy assignment
  const PrefixTree& operator=(const PrefixTree&);
  //Utility function:  checks whether all characters in a string are letters
  bool isAllLetters(const string&) const;
  //Returns the root of the prefix tree
  PrefixTreeNode* getRoot() { return root; };
  //Returns the root of the prefix tree
  const PrefixTreeNode* getRoot() const { return root; };
  //TODO:  returns whether or not the given word belongs to the prefix tree
  bool contains(const string&);
  //TODO:  adds the given word to the prefix tree
  void addWord(const string&);
  //Destructor
  ~PrefixTree();
};

/*
  Node of a prefix tree
 */
class PrefixTreeNode
{
  friend PrefixTree;
private:
  char c;
  bool final;
  PrefixTreeNode* link[ALPHABET_SIZE];
public:
  //Constructs a new node
  PrefixTreeNode();
  //Copy constructor
  PrefixTreeNode(const PrefixTreeNode&);
  //Copy assignment
  const PrefixTreeNode& operator=(const PrefixTreeNode&);
  //Returns the character this node contains
  char getChar() const { return c; }
  //Returns whether this node is the end of a word
  bool isFinal() const { return final; }
  //Changes whether this node is the end of a word
  void setFinal(bool b) { final = b; }
  //Returns the node corresponding to the given character
  PrefixTreeNode* getChild(char);
  //Returns the node corresponding to the given character
  const PrefixTreeNode* getChild(char) const;
  //Adds a child corresponding to the given character
  void addChild(char);
  //Removes the child corresponding to the given character
  void deleteChild(char);
  //Destructor
  ~PrefixTreeNode();
};

ostream& operator<<(ostream&, const PrefixTree&);
ostream& operator<<(ostream&, const PrefixTreeNode&);
#endif