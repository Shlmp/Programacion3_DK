El árbol de búsqueda binaria es la base para la implementación de dos clases de colecciones de librerias, *set* y *map*.

# 4.1 - Preliminares
Los árboles pueden ser definidos de varias formas, una de ellas es de manera recursiva. Un árbol es una colección de nodos, la cual puede estar vacía. Sin embargo, en caso de no estar vacía, el árbol contiene un nodo importante llamado *raíz* (*r*) y cero o más (sub)árboles $T_1,T_2...T_k$, cuyas raíces están conectadas por un borde directo de *r*.

La raíz de cada subárbol es un **hijo** de *r*, y *r* es el **padre** de cada raíz de los subárboles.

Por la definición de recursividad, un árbol es un conjunto de *N* nodos, uno de ellos siendo la raíz, y $N-1$ bordes. Hay $N-1$ bordes ya que cada borde conecta algún nodo a su padre, y cada nodo con excepción de la raíz tiene un padre.
![[Pasted image 20231026120303.png]]
Para cada nodo $n_i$, la **profundidad** de $n_i$ es la longitud del camino único desde la raíz a $n_i$. La **altura** de $n_i$, es la longitud del camino más largo desde $n_i$ a una hoja.

## 4.1.1 - Implementación de Árboles
A way to implement a tree is by having in each node a link to each child of the node. Nevertheless, since the number of children per node can vary greatly and it is not known in advance, it might not be possibleto make the children direct links in the data structure, since there would be too much wasted space.

# 4.2 - Binary Tree
![[Pasted image 20231028182400.png]]
A *Binary Tree* is a tree in which no node has more than 2 children. A property important to binary trees is that the depth of an average binary tree is significantly smaller than *N* ($O(\sqrt{N})$). Meanwhile, for the *Binary Search Tree*, the average value of the depth  is $O(Log N)$. Nevertheless, the depth can be as large as $N-1$.

**N-1**
![[Pasted image 20231028182415.png]]

## 4.2.1 - Implementation
Since a binary tree will only have at most 2 children, there can be a direct link to them, having a similar structure in terms of declaring tree nodes to Double Linked Lists (DLL); a node is a structure consisting of the *element* information & two pointers (**left** & **right**) to other nodes.

## 4.2.2 - Expression Trees
![[Pasted image 20231028183115.png]]
The leaves of an *Expression Tree* are known as **operands**, such as constants or variable names. The other nodes contain **operators**. 

### Constructing an Expression Tree
In order to construct an Expression Tree, it is first needed to identify whether the expression being read is an operand or an operator. If it is an operand, a one-node tree is created and pushes a pointer to it into a stack. If it is an operator, we pop pointers to two trees $T_1$ & $T_2$ from the stack, having $T_1$ be popped first. Only to then form a new tree whose root is the operator and whose **left** and **right** children point to $T_2$ & $T_1$ respectively. A pointer to the newly created tree is pushed onto the stack.

#### Example
Having the input
![[Pasted image 20231028185321.png]]

![[Pasted image 20231028185346.png]]
![[Pasted image 20231028185407.png]]
![[Pasted image 20231028185429.png]]
![[Pasted image 20231028185633.png]]
![[Pasted image 20231028185654.png]]
![[Pasted image 20231028185718.png]]


# 4.4 - AVL Trees
AVL, standing for Adelson-Velskii and Landis, is a binary search tree with a **balance condition**. This balance condition must be easy to maintain and it should ensure that the depth of the tree is $O(LogN)$. The simplest way is to require that both the left and right subtrees have the same height.
![[Pasted image 20231028190410.png]]

Another balance condition would consist in that every node must have left and right subtrees of the same height. If the height of an empty subtree is defined to be -1, then only perfectly balanced trees of $2^k-1$ nodes would fulfill the criteria. Thus, although this guarantees trees of small depth, the balance condition is too rigid to be useful and needs to be relaxed.

![[Pasted image 20231028192732.png]]
An AVL Tree is identical to a binary search tree, except that for every node in the tree, the height of the left and right subtrees can differ by at most 1, the height of an empty tree is defined to be -1.
Height information is kept for each node. All tree operations can be performed in $O(log N)$ time, except for insertion and deletion.

When there is an insert, we need to update all the balancing information for the nodes on the path back to the root. However, the reason why insertion could be potentially difficult is that inserting a node could violate the AVL tree property. In such case, the property has to be restored before the insertion step is considered over. This can be dealt with a simple modification to the tree called **rotation**.
After an insertion, only nodes that are on the path from the insertion to the root may have their balance altered, this is because only those nodes have their subtrees altered. As we follow the path to the root and update the balancing information, a new node whose new balance violates the AVL condition can be found.

## 4.4.1 - Single Rotation
![[Pasted image 20231028193854.png]]
In this example, Node $k_2$ violates the AVL balance property because its left subtree is two levels deeper than its right one (marked by the dotted lines). The only situation in which the AVL property is satisfied  before an insertion but violate it afterwards is the following.

Subtree X has grown to an extra level, causing it to be exactly two levels deeper than Z. Y cannot be at the same level as the new X because then $k_2$ would have been out of balance before the insertion, and Y cannot be at the same level as Z because then $k_1$ would be the first node on the path toward the root that was in violation of the AVL balancing condition.

In order to rebalance the tree, we would need to move X up a level and Z down a level, although this would be more than the AVL property would require. To do this, we must rearrange nodes into an equivalent tree.
This can be achieved by taking $k_1$ as the new root. Due to the binary search tree property tells us that in the original tree $k_2>k_1$, so $k_2$ becomes the right child of $k_1$ in the new tree. Thus, X remains as the left child of $k_1$ and Z remains as the right child of $k_2$. Subtree Y,  which holds items between both $k_1$ and $k_2$, in the original tree, can be placed as the left child of $k_2$.
As a result of this, only requiring a few pointer changes, we have a new binary search tree that follows the AVL properties, since X moves up one level, Y stays the same and Z moves down one level. This way, both $k_1$ & $k_2$ satisfy the AVL requirements as well as having their entire subtrees have the exact same height.
No only that, but the height of the new subtree is exactly the same as the original subtree before the insertion that caused X to grow, meaning there is no need for another update of heights on the path to the root, as well as not needing another rotation.

![[Pasted image 20231029112935.png]]

### Example
![[Pasted image 20231029113642.png]]
![[Pasted image 20231029113707.png]]
![[Pasted image 20231029113720.png]]
![[Pasted image 20231029113736.png]]

## 4.4.2 - Double Rotation
As useful as a single rotation may be, not always will it work. There are moments in which a single rotation will not suffice, hence the implementation of a *Double Rotation*. 
![[Pasted image 20231029143341.png]]
In this example, Y is too deep, and a single rotation would not suffice , as such, to rebalance, $k_3$ cannot remain as the root and as **Figure 4.37** shows, a single rotation between $k_3$ & $k_1$ won't work either, hence, the only other option is to place $k_2$ as the new root. This forces $k_1$ to be the left child of $k_2$ and $k_3$ to be its right child, determining the locations of the four subtrees. 
![[Pasted image 20231029144050.png]]

### Example
![[Pasted image 20231029144346.png]]
![[Pasted image 20231029144402.png]]
![[Pasted image 20231029144616.png]]
![[Pasted image 20231029144628.png]]
![[Pasted image 20231029144643.png]]
![[Pasted image 20231029144707.png]]

# Conclusiones e Investigación
Un árbol AVL es un árbol de búsqueda binaria auto-balanceable donde cada nodo mantiene una información extra (balance), este valor puede ser -1, 0 o 1.

El balance de un nodo es la diferencia entre la altura del subárbol izquierdo y la del subárbol derecho de ese nodo.
$$height(AVL->left)-height(AVL->right)<2$$
También teniendo su definición simétrica.
$$height(AVL->right)-height(AVL->left)<2$$

Durante el proceso de insercción o eliminación, un desbalance puede ocurrir, la altura de alguno de los nodos es mayor que 1. Existen 4 casos que corrigen el desbalanceo del árbol AVL:
1. **Caso 1**: rotación simple derecha.
2. **Caso 2**: rotación simple izquierda.
3. **Caso 3**: rotación doble izquierda derecha.
4. **Caso 4**: rotación doble derecha izquierda.

## Ejemplos de rotaciones
### Rotación Simple
![[Pasted image 20231029152842.png]]
Se rotan A y B.
B "baja" a ser el hijp derecho de A, *y* pasa a ser el hijo izquierdo de B.



![[Pasted image 20231029153017.png]]
Se añaden 1 y 3.
Al tener desbalance en 8 (por tener el lado izquierdo con altura mayor a 1), se rota a la derecha 8 y sus hijos.
8 pasa a ser el hijo derecho de 4 y 6 pasa a ser el hijo izquierdo de 8.


### Rotación Doble
![[Pasted image 20231029153322.png]]
a -> b -> c
**Primera rotación**
Se rotan A y B, A pasa a ser el hijo izquierdo de B.
x pasa a ser el hijo derecho de A.

***Árbol sigue desbalanceado***

**Segunda rotación**
Se rotan B y C, C pasa a ser el hijo derecho de B.
y pasa a ser el hijo izquierdo de C.



![[Pasted image 20231029153906.png]]
Se añaden 5 y 7 como hijos de 6, se genera desbalance en 8.
**Primera rotación**
Se rotan 6 y 4, 4 se vuelve el hijo izquierdo de 6.
5 se vuelve el hijo derecho de 4.

**Segunda rotación**
Se rotan 6 y 8, 8 se vuelve el hijo derecho de 6.
7 se vuelve el hijo izquierdo de 8.
## Usos de un AVL
Ayuda a reducir el tiempo de complejidad en un árbol de búsqueda binaria.

![[Pasted image 20231029154939.png]]

### Ventajas
![[Pasted image 20231029155207.png]]

### Desventajas
![[Pasted image 20231029155243.png]]


## Dudas
Sigo con dudas en cuanto a cómo identificar qué nodos son los que se necesitan balancear, qué hijos son afectados o deben de moverse o en qué momento se debería de balancear y, por ende, cuándo se puede saber si un árbol está desbalanceado o no y saber si se debería de usar una rotación simple o una doble.

# Referencias
- V. mi P. Completo, “Fundamentos de la Programación Orientada a Objetos,” _Blogspot.com_. [Online]. Available: https://fundamentospoorrr.blogspot.com/2017/06/arboles-binarios-balanceados-avl.html. [Accessed: 29-Oct-2023].
- A. A. Follow, “AVL tree data structure,” _GeeksforGeeks_, 02-Jan-2023. [Online]. Available: https://www.geeksforgeeks.org/introduction-to-avl-tree/. [Accessed: 29-Oct-2023].
- “AVL Trees Notes for GATE,” _BYJUS_, 05-Nov-2021. [Online]. Available: https://byjus.com/gate/avl-trees-notes/. [Accessed: 29-Oct-2023].
- “AVL tree,” _Programiz.com_. [Online]. Available: https://www.programiz.com/dsa/avl-tree. [Accessed: 29-Oct-2023].