class Node{
    constructor(value){
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree{
    constructor(){
        this.root = null;
    }
    insert(root = this.root,value){
        let new_node = new Node(value);
        if(root == null){
           console.log(root == null)
           root = new_node;
           console.log(root);
           return;
        }
        if(value < root.value){
            this.insert(root.left);
        }else{
            this.insert(root.right);
        }
    }
}

let bst = new BinarySearchTree();
bst.insert(5);
bst.insert(2);
bst.insert(6);

console.log(bst);