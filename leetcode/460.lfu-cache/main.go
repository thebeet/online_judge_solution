package main

import "fmt"

type LFU[K string | int, V any] interface {
	Set(k K, v *V)
	Get(k K) (v *V, ok bool)
	Size() int
}

type freqNode[K string | int, V any] struct {
	freq int
	prev *freqNode[K, V]
	next *freqNode[K, V]

	head *dataNode[K, V]
	tail *dataNode[K, V]
}

type dataNode[K string | int, V any] struct {
	key   K
	value *V
	freq  *freqNode[K, V]
	next  *dataNode[K, V]
	prev  *dataNode[K, V]
}

type lfu[K string | int, V any] struct {
	capacity int
	size     int
	hash     map[K]*dataNode[K, V]
	root     *freqNode[K, V]
}

func NewLFU[K string | int, V any](capacity int) LFU[K, V] {
	return &lfu[K, V]{
		capacity: capacity,
		size:     0,
		hash:     make(map[K]*dataNode[K, V]),
		root:     nil,
	}
}

func (c *lfu[K, V]) insertDataNode(f *freqNode[K, V], n *dataNode[K, V]) {
	n.next = f.head
	n.prev = nil
	if f.head != nil {
		f.head.prev = n
	}
	f.head = n
	if f.tail == nil {
		f.tail = n
	}
}

func (c *lfu[K, V]) removeDataNode(f *freqNode[K, V], n *dataNode[K, V]) {
	prev, next := n.prev, n.next
	if prev != nil {
		prev.next = next
	} else {
		f.head = next
	}
	if next != nil {
		next.prev = prev
	} else {
		f.tail = prev
	}
	n.prev, n.next = nil, nil
}

func (c *lfu[K, V]) addFreqNode(current *freqNode[K, V], freq int) {
	if current.next == nil || current.next.freq != freq {
		newFreqNode := &freqNode[K, V]{
			freq: freq,
			next: current.next,
			prev: current,
		}
		if current.next != nil {
			current.next.prev = newFreqNode
		}
		current.next = newFreqNode
	}

}

func (c *lfu[K, V]) removeEmptyFreqNode(f *freqNode[K, V]) {
	if f.head == nil {
		if f.next != nil {
			f.next.prev = f.prev
		}
		if f.prev != nil {
			f.prev.next = f.next
		} else {
			c.root = f.next
		}
	}
}

func (c *lfu[K, V]) evict() {
	delete(c.hash, c.root.tail.key)
	c.removeDataNode(c.root, c.root.tail)
	c.removeEmptyFreqNode(c.root)
	c.size--
}

func (c *lfu[K, V]) Set(k K, v *V) {
	if node, ok := c.hash[k]; ok {
		node.value = v
		fNode := node.freq
		c.addFreqNode(fNode, fNode.freq+1)
		node.freq = fNode.next
		c.removeDataNode(fNode, node)
		c.insertDataNode(node.freq, node)
		c.removeEmptyFreqNode(fNode)
	} else {
		c.size++
		for c.capacity < c.size {
			c.evict()
		}
		if c.root == nil || c.root.freq != 1 {
			newFreqNode := &freqNode[K, V]{
				freq: 1,
				next: c.root,
			}
			if c.root != nil {
				c.root.prev = newFreqNode
			}
			c.root = newFreqNode
		}
		node := &dataNode[K, V]{
			key:   k,
			value: v,
			freq:  c.root,
		}

		c.insertDataNode(c.root, node)
		c.hash[k] = node
	}
}

func (c *lfu[K, V]) Get(k K) (v *V, ok bool) {
	if node, ok := c.hash[k]; ok {
		fNode := node.freq
		c.addFreqNode(fNode, fNode.freq+1)
		node.freq = fNode.next
		c.removeDataNode(fNode, node)
		c.insertDataNode(node.freq, node)
		c.removeEmptyFreqNode(fNode)
		return node.value, true
	} else {
		return nil, false
	}
}

func (c *lfu[K, V]) Size() int {
	return c.size
}

type LFUCache struct {
	lfucache LFU[int, int]
}

func Constructor(capacity int) LFUCache {
	return LFUCache{lfucache: NewLFU[int, int](capacity)}
}

func (this *LFUCache) Get(key int) int {
	if v, ok := this.lfucache.Get(key); ok {
		return *v
	} else {
		return -1
	}
}

func (this *LFUCache) Put(key int, value int) {
	this.lfucache.Set(key, &value)
}

func main() {
	lfu := Constructor(2)
	lfu.Put(1, 1)
	lfu.Put(2, 2)
	fmt.Println(lfu.Get(1))
	lfu.Put(3, 3)
	fmt.Println(lfu.Get(2))
	fmt.Println(lfu.Get(3))
	lfu.Put(4, 4)
	fmt.Println(lfu.Get(1))
	fmt.Println(lfu.Get(3))
	fmt.Println(lfu.Get(4))
}
