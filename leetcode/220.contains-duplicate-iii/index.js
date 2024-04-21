const MaxLevel = 32;
const P = 1.0 / Math.E;

class Node {
    constructor(level, value) {
        this.level = level;
        this.value = value;
        this.links = [];
        for (let i = 0; i <= level; ++i) {
            this.links.push({
                next: null,
                prev: null
            });
        }
    }
}

class Skiplist {
    constructor(cmp, eq) {
        this.level = 0;
        this.cmp = cmp || ((a, b) => a < b);
        this.eq = eq || ((a, b) => a === b);
        this.count = 0;
        this.header = new Node(MaxLevel, -Infinity);
    }

    _randomLevel() {
        let result = 0;
        while ((Math.random() < P) && (result <= this.level)) {
            result++;
        }
        return Math.min(result, MaxLevel);
    }

    find(value) {
        let currentNode = this.header;
        for (let i = this.level; i >= 0; --i) {
            while (currentNode.links[i].next) {
                if (this.eq(currentNode.links[i].next.value, value)) {
                    return currentNode.links[i].next;
                } else if (this.cmp(currentNode.links[i].next.value, value)) {
                    currentNode = currentNode.links[i].next;
                } else {
                    break;
                }
            }
        }
        return null;
    }

    remove(value) {
        let node = this.find(value);
        if (node) {
            for (let i = 0; i <= node.level; ++i) {
                let prevNode = node.links[i].prev;
                let nextNode = node.links[i].next;
                prevNode.links[i].next = nextNode;
                if (nextNode) {
                    nextNode.links[i].prev = prevNode;
                }
            }
            return true;
        }
        return false;
    }

    erase(value) {
        return this.remove(value);
    }

    search(value) {
        let node = this.find(value);
        if (node) {
            return true;
        } else {
            return false;
        }
    }

    add(value) {
        let level = this._randomLevel();
        let newNode = new Node(level, value);
        this.level = Math.max(this.level, level);
        let currentNode = this.header;
        for (let i = this.level; i >= 0; --i) {
            while (currentNode.links[i].next && this.cmp(currentNode.links[i].next.value, value)) {
                currentNode = currentNode.links[i].next;
            }
            if (i <= level) {
                let nextNode = currentNode.links[i].next;
                newNode.links[i].prev = currentNode;
                currentNode.links[i].next = newNode;
                if (nextNode) {
                    newNode.links[i].next = nextNode;
                    nextNode.links[i].prev = newNode;
                }
            }
        }
        return newNode;
    }
};

function containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) {
    const skiplist = new Skiplist();
    for (let i = 0; i < nums.length; i++) {
        if (i > indexDiff) {
            skiplist.remove(nums[i - indexDiff - 1]);
        }
        if (skiplist.search(nums[i])) {
            return true;
        }
        const node = skiplist.add(nums[i]);
        if (node.links[0].prev && (node.links[0].prev.value + valueDiff >= nums[i])) {
            return true;
        }
        if (node.links[0].next && (nums[i] + valueDiff >= node.links[0].next.value )) {
            return true;
        }
    }
    return false;
};