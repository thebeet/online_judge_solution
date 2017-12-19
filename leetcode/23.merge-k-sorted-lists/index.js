/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */

class Heap {
    constructor(cmp) {
        this.lists = [];
        this.lists.push(null);
        this.cmp = cmp;
        if (!this.cmp) {
            this.cmp = function (a, b) {
                if (a < b) {
                    return -1;
                }
                if (a > b) {
                    return 1;
                }
                return 0;
            };
        }
    }

    count() {
        return this.lists.length - 1;
    }

    top() {
        if (this.count() > 0) {
            return this.lists[1];
        } else {
            return null;
        }
    }

    pop() {
        let topValue = this.top();
        this._swap(1, this.count());
        this.lists.splice(this.count(), 1);
        this.turndown(1);
        return topValue;
    }

    push(value) {
        this.lists.push(value);
        this.turnup(this.count());
    }

    _swap(id1, id2) {
        let tmp = this.lists[id1];
        this.lists[id1] = this.lists[id2];
        this.lists[id2] = tmp;
    }

    turnup(id) {
        if (id > 1) {
            let fatherId = id >> 1;
            if (this.cmp(this.lists[id], this.lists[fatherId]) < 0) {
                this._swap(id, fatherId);
                this.turnup(fatherId);
            }
        }
    }

    turndown(id) {
        let child1 = id << 1;
        let child2 = child1 + 1;
        let smallChild = id;
        if ((child1 <= this.count()) && (this.cmp(this.lists[smallChild], this.lists[child1]) > 0)) {
            smallChild = child1;
        }
        if ((child2 <= this.count()) && (this.cmp(this.lists[smallChild], this.lists[child2]) > 0)) {
            smallChild = child2;
        }
        if (smallChild !== id) {
            this._swap(id, smallChild);
            this.turndown(smallChild);
        }
    }
}

var mergeKLists = function(lists) {
    let heap = new Heap((nodeA, nodeB) => {
        if (nodeA.val < nodeB.val) {
            return -1;
        }
        if (nodeA.val > nodeB.val) {
            return 1;
        }
        return 0;
    });
    for (let list of lists) {
        if (list) {
            heap.push(list);
        }
    }
    let result = [];
    while (heap.count() > 0) {
        let node = heap.pop();
        result.push(node.val);
        if (node.next) {
            heap.push(node.next);
        }
    }
    return result;
};
