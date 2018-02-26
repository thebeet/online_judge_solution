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

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var countSmaller = function(nums) {
    let result = [];
    let N = nums.length;
    let treap = new Treap();
    for (let i = N - 1; i >= 0; i--) {
        result.push(treap.countLessOrEqualThen(nums[i] - 0.5));
        treap.insert(nums[i]);
    }
    result.reverse();
    return result;
};
