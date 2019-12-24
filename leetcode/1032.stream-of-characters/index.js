class TrieNode {
    constructor(value) {
        this.value = value;
        this.fail = undefined;
        this.children = {};
    }

    getChild(value) {
        return this.children[value];
    }
}

TrieNode.Root = Symbol('Root');
TrieNode.EndOfString = Symbol('EndOfString');

class Trie {
    constructor() {
        this.root = new TrieNode(TrieNode.Root);
    }

    addPattern(pattern) {
        let currentPos = this.root;
        let i = 0;
        for (let char of pattern) {
            if (currentPos.getChild(char) === undefined) {
                currentPos.children[char] = new TrieNode(char);
            }
            currentPos = currentPos.children[char];
            i += 1;
        }
        if (!(TrieNode.EndOfString in currentPos.children)) {
            currentPos.children[TrieNode.EndOfString] = new TrieNode(TrieNode.EndOfString);
        }
    }

    search(str) {
        let currentPos = this.root;
        for (let char of str) {
            if (char in currentPos.children) {
                currentPos = currentPos.children[char];
            } else {
                return false;
            }
        }
        return (TrieNode.EndOfString in currentPos.children);
    }

    buildAhoCorasick() {
        let queue = [];
        for (let subRootKey in this.root.children) {
            let subRoot = this.root.children[subRootKey];
            subRoot.fail = this.root;
            queue.push(subRoot);
        }
        while (queue.length > 0) {
            let currentNode = queue.shift();
            for (let child in currentNode.children) {
                let childNode = currentNode.children[child];
                childNode.fail = this.root;
                for (let failNode = currentNode.fail; failNode !== undefined; failNode = failNode.fail) {
                    let failChild = failNode.getChild(childNode.value);
                    if (failChild) {
                        childNode.fail = failChild;
                        break;
                    }
                }
                queue.push(childNode);
            }
        }
    }
}

/**
 * @param {string[]} words
 */
var StreamChecker = function(words) {
    this.trie = new Trie();
    for (let word of words) {
        this.trie.addPattern(word);
    }
    this.trie.buildAhoCorasick();
};

/** 
 * @param {character} letter
 * @return {boolean}
 */
StreamChecker.prototype.query = function(letter) {
    let _query = function (node, letter) {
        if (node === undefined) {
            node = this.trie.root;
        }
        while (node) {
            let child = node.getChild(letter);
            if (child) {
                node = child;
                return node;
            } else {
                node = node.fail;
            }
        }
        return undefined;
    };
    this.currentPos = _query.bind(this)(this.currentPos, letter);
    return _query.bind(this)(this.currentPos, TrieNode.EndOfString) !== undefined;
};