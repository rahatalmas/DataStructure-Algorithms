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
            console.log(temp);
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
        //return;
    }
}


let bt = new BinaryTree();
//bt.insert(5);
//bt.insert(6);
for(let i=0;i<10;i++){
    bt.insert(i);
}
console.log(bt);