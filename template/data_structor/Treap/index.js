class TreapNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
        this.parent = null;
        this.rank = Math.floor(Math.random() * Number.MAX_SAFE_INTEGER);
        this.size = 1;
    }

    leftSize() {
        return this.left ? this.left.size : 0;
    }

    rightSize() {
        return this.right ? this.right.size : 0;
    }
}

class Treap {
    constructor(cmp) {
        if (cmp) {
            this._cmp = cmp;
        } else {
            this._cmp = (a, b) => {
                if (a < b) return -1;
                if (a > b) return 1;
                return 0;
            };
        }
        this.root = null;
    }

    insert(value) {
        if (this.root) {
            this._insert(this.root, value);
            while (this.root.parent) {
                this.root = this.root.parent;
            }
        } else {
            this.root = new TreapNode(value);
        }
    }

    remove(node) {
        if (this.root === null) return;
        let fakeNode = new TreapNode();
        this.root.parent = fakeNode;
        fakeNode.left = this.root;
        let nodeChildType = 'left';
        if (node.parent.right === node) {
            nodeChildType = 'right';
        }
        
        if ((node.left === null) && (node.right === null)) {
            node.parent[nodeChildType] = null;
        } else {
            if (node.left === null) {
                node.parent[nodeChildType] = node.right;
                node.right.parent = node.parent;
            } else if (node.right === null) {
                node.parent[nodeChildType] = node.left;
                node.left.parent = node.parent;
            } else {
                let rightMinNode = node.right;
                let rightMinNodeChildType = 'right';
                while (rightMinNode.left !== null) {
                    rightMinNode.size -= 1;
                    rightMinNode = rightMinNode.left;
                    rightMinNodeChildType = 'left';
                }
                rightMinNode.parent[rightMinNodeChildType] = rightMinNode.right;
                if (rightMinNode.right) {
                    rightMinNode.right.parent = rightMinNode.parent;
                }
                rightMinNode.size = node.size;
                rightMinNode.left = node.left;
                rightMinNode.right = node.right;
                rightMinNode.parent = node.parent;
                rightMinNode.rank = node.rank;
                node.left.parent = rightMinNode;
                if (node.right) {
                    node.right.parent = rightMinNode;
                }
                node.parent[nodeChildType] = rightMinNode;
                node = rightMinNode;
            }
        }
        let currentNode = node;
        while (currentNode.parent !== null) {
            currentNode.parent.size -= 1;
            currentNode = currentNode.parent;
        }
        this.root = fakeNode.left;
        if (this.root) {
            this.root.parent = null;
        }
    }

    isEmpty() {
        return this.root === null;
    }

    size() {
        return this.isEmpty() ? 0 : this.root.size;
    }

    _insert(node, value) {
        node.size += 1;
        if (this._cmp(value, node.value) === -1) {
            if (node.left) {
                this._insert(node.left, value);
            } else {
                node.left = new TreapNode(value);
                node.left.parent = node;
                this._turnup(node.left);
            }
        } else {
            if (node.right) {
                this._insert(node.right, value);
            } else {
                node.right = new TreapNode(value);
                node.right.parent = node;
                this._turnup(node.right);
            }
        }
    }

    _turnup(node) {
        while (node.parent) {
            if (node.rank < node.parent.rank) {
                this._rotate(node);
            } else {
                break;
            }
        }
    }

    _rotate(node) {
        let parentNode = node.parent;
        if (!parentNode) return;
        let parentParentNode = node.parent.parent;
        if (parentNode.left === node) {
            let parentNodeSize = parentNode.size;
            parentNode.size = parentNode.size - node.leftSize() - 1;
            node.size = parentNodeSize;
            parentNode.left = node.right;
            if (node.right) {
                node.right.parent = parentNode;
            }
            node.right = parentNode;
            parentNode.parent = node;
        } else {
            let parentNodeSize = parentNode.size;
            parentNode.size = parentNode.size - node.rightSize() - 1;
            node.size = parentNodeSize;
            parentNode.right = node.left;
            if (node.left) {
                node.left.parent = parentNode;
            }
            node.left = parentNode;
            parentNode.parent = node;
        }
        if (parentParentNode) {
            if (parentParentNode.left === parentNode) {
                parentParentNode.left = node;
            } else {
                parentParentNode.right = node;
            }
        }
        node.parent = parentParentNode;
    }

    search(value) {
        let resultNode = null;
        let pathStrategy = (node) => {
            let cmpRet = this._cmp(value, node.value);
            if (cmpRet === 0) {
                resultNode = node;
                return null;
            }
            return (cmpRet === -1) ? node.left : node.right;
        };
        if (this.root) {
            this._traversal(this.root, pathStrategy);
        }
        return resultNode;
    }

    searchNearestNodeFromLeft(value) {
        let resultNode = null;
        let pathStrategy = (node) => {
            let cmpRet = this._cmp(value, node.value);
            if (cmpRet === 0) {
                resultNode = node;
                return null;
            }
            if (cmpRet === 1) {
                resultNode = node;
                return node.right;
            }
            return node.left;
        };
        if (this.root) {
            this._traversal(this.root, pathStrategy);
        }
        return resultNode;
    }

    traversal(pathStrategy, nodeCallback) {
        if (this.root) {
            this._traversal(this.root, pathStrategy, nodeCallback);
        }
    }

    _traversal(node, pathStrategy, nodeCallback) {
        if (node) {
            if (nodeCallback) {
                nodeCallback(node);
            }
            this._traversal(pathStrategy(node), pathStrategy, nodeCallback);
        }
    }

    countLessOrEqualThen(value) {
        let count = 0;
        let pathStrategy = (node) => {
            return (this._cmp(value, node.value) === -1) ? node.left : node.right;
        };
        let countCallback = (node) => {
            if (this._cmp(value, node.value) >= 0) {
                count += node.leftSize() + 1;
            }
        };
        this.traversal(pathStrategy, countCallback);
        return count;
    }
}

