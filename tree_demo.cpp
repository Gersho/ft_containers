#include "Tree.hpp"
#include <iostream>
#include <memory>

void show(struct ft::node<int> *p, int l, ft::Tree<int, std::allocator<int>, std::less<int> > *avl)
{
   int i;
   if (p != NULL) {
   show(p->right, l+ 1, avl);
   std::cout<<" ";
   if (p == avl->get_root())
      std::cout << "Root -> ";
   for (i = 0; i < l&& p != avl->get_root(); i++)
      std::cout << " ";
      std::cout << *(p->data);
      show(p->left, l + 1, avl);
   }
}

int main() {
   int c, i;
   ft::Tree<int, std::allocator<int>, std::less<int> > avl;

   while (1) {
      std::cout << "1.Insert Element into the tree" << std::endl;
      std::cout << "2.show Balanced AVL Tree" << std::endl;
      // std::cout << "3.InOrder traversal" << std::endl;
      // std::cout << "4.PreOrder traversal" << std::endl;
      // std::cout << "5.PostOrder traversal" << std::endl;
      std::cout << "9.Exit" << std::endl;
      std::cout << "Enter your Choice: ";
      std::cin >> c;
      switch (c) {
         case 1:
            std::cout << "Enter value to be inserted: ";
            std::cin >> i;
            avl.set_root(avl.insert(avl.get_root(), i));
         break;
         case 2:
            if (avl.get_root() == NULL) {
               std::cout << "Tree is Empty" << std::endl;
               continue;
            }
            std::cout << "Balanced AVL Tree:" << std::endl;
            show(avl.get_root(), 1, &avl);
            std::cout<<std::endl;
         break;
        //  case 3:
        //     std::cout << "Inorder Traversal:" << std::endl;
        //     avl.inorder(r);
        //     std::cout << std::endl;
        //  break;
        //  case 4:
        //     std::cout << "Preorder Traversal:" << std::endl;
        //     avl.preorder(r);
        //     std::cout << std::endl;
        //  break;
        //  case 5:
        //     std::cout << "Postorder Traversal:" << std::endl;
        //     avl.postorder(r);
        //     std::cout << std::endl;
        //  break;
         case 9:
            exit(1);
         break;
         default:
            std::cout << "Wrong Choice" << std::endl;
      }
   }
   return 0;
}