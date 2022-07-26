#include "Tree.hpp"
#include "utility.hpp"
#include <iostream>
#include <memory>

void show(struct ft::node<ft::pair< int, int >> *p, int l, ft::Tree<ft::pair< int, int >, std::allocator< ft::pair< int, int > >, std::less<ft::pair< int, int > > > *avl)
{
   int i;
   if (p != NULL)
   {
      show(p->right, l+ 1, avl);
      std::cout<<" ";
      if (p == avl->get_root())
         std::cout << "Root -> ";
      for (i = 0; i < l&& p != avl->get_root(); i++)
         std::cout << " ";
         std::cout << p->data->first << "(" << p->height << ")";
         show(p->left, l + 1, avl);
   }
}

int main() {
   int c, i;
   ft::Tree<ft::pair< int, int >, std::allocator< ft::pair< int, int > >, std::less<ft::pair< int, int > > > avl;
   int values[10] = { 50, 10, 40, 20, 25, 30, 35, 5, 1, 45 };

   while (1) {
      std::cout << "1.Insert Element into the tree" << std::endl;
      std::cout << "2.show Balanced AVL Tree" << std::endl;
       std::cout << "3.Erase Element from tree" << std::endl;
       std::cout << "4.Autofill" << std::endl;
      std::cout << "5.Autodel" << std::endl;
      std::cout << "9.Exit" << std::endl;
      std::cout << "Enter your Choice: ";
      std::cin >> c;
      switch (c) {
         // case 1:
         //    std::cout << "Enter value to be inserted: ";
         //    std::cin >> i;
         //    avl.set_root(avl.insert(avl.get_root(), i));
         // break;
         case 2:
            if (avl.get_root() == NULL) {
               std::cout << "Tree is Empty" << std::endl;
               continue;
            }
            std::cout << "Balanced AVL Tree:" << std::endl;
            show(avl.get_root(), 1, &avl);
            std::cout<<std::endl;
         break;
         // case 3:
         //    std::cout << "Enter value to be erased: ";
         //    std::cin >> i;
         //    avl.set_root(avl.erase(avl.get_root(), i));
         // break;
         case 4:
            avl.set_root(avl.insert(avl.get_root(), ft::make_pair<int, int>( 5, 5 )));
            avl.set_root(avl.insert(avl.get_root(), ft::make_pair<int, int>( 15, 5 )));
            avl.set_root(avl.insert(avl.get_root(), ft::make_pair<int, int>( 75, 5 )));
            avl.set_root(avl.insert(avl.get_root(), ft::make_pair<int, int>( 45, 5 )));
            avl.set_root(avl.insert(avl.get_root(), ft::make_pair<int, int>( 55, 5 )));
            avl.set_root(avl.insert(avl.get_root(), ft::make_pair<int, int>( 245, 5 )));
            avl.set_root(avl.insert(avl.get_root(), ft::make_pair<int, int>( 35, 5 )));
            avl.set_root(avl.insert(avl.get_root(), ft::make_pair<int, int>( 105, 5 )));
            avl.set_root(avl.insert(avl.get_root(), ft::make_pair<int, int>( 305, 5 )));
            avl.set_root(avl.insert(avl.get_root(), ft::make_pair<int, int>( 50, 5 )));
         break;
         // case 5:   
         //    avl.set_root(avl.erase(avl.get_root(), ));
         //    avl.set_root(avl.erase(avl.get_root(), ));
         //    avl.set_root(avl.erase(avl.get_root(), ));
         //    avl.set_root(avl.erase(avl.get_root(), ));
         //    avl.set_root(avl.erase(avl.get_root(), ));
         //    avl.set_root(avl.erase(avl.get_root(), ));
         //    avl.set_root(avl.erase(avl.get_root(), ));
         // break;
         case 9:
            exit(1);
         break;
         default:
            std::cout << "Wrong Choice" << std::endl;
      }
   }
   return 0;
}