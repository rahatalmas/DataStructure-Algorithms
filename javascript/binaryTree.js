class Node{
    constructor(value){
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree{
    constructor(){
        this.root = null;
    }
    insert(value){
        let new_node = new Node(value);
        if(this.root === null){
           this.root = new_node;
           return;
        }
        let l = [];
        l.push(this.root);
        while(l.length != 0){
            let temp = l.shift();
            if(temp.left == null){
                temp.left = new_node;
                return;
            }else{
                l.push(temp.left);
            }
            if(temp.right == null){
                temp.right = new_node;
                return;
            }else{
                l.push(temp.right);
            }
        }
    }
    inorderPrint(root = this.root){
        if(root == null){
            return;
        }
        this.inorderPrint(root.left);
        console.log(root.value);
        this.inorderPrint(root.right);
    }
    preoderPrint(root = this.root){
        if(root == null){
            return;
        }
        console.log(root.value);
        this.preoderPrint(root.left);
        this.preoderPrint(root.right);
    }
    postorderPrint(root = this.root){
        if(root == null){
            return;
        }
        this.postorderPrint(root.left);
        this.postorderPrint(root.right);
        console.log(root.value);
    }
}


let bt = new BinaryTree();
for(let i=1;i<10;i++){
    bt.insert(i);
}
//console.log(bt);
console.log("inorder Traversal -> ");
bt.inorderPrint();
console.log("preorder Traversal -> ");
bt.preoderPrint();
console.log("postorder Traversal -> ");
bt.postorderPrint();