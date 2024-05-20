package lru

import "container/list"

type node[K comparable, V any] struct {
	key   K
	value *V
}

type lru[K comparable, V any] struct {
	hash   map[K]*list.Element
	dlList *list.List

	capacity int
	size     int
}

func newLRU[K comparable, V any](capacity int) *lru[K, V] {
	return &lru[K, V]{
		hash:     make(map[K]*list.Element),
		dlList:   list.New().Init(),
		capacity: capacity,
		size:     0,
	}
}

func (l *lru[K, V]) Get(k K) *V {
	if v, ok := l.hash[k]; ok {
		l.dlList.MoveToFront(v)
		return v.Value.(*node[K, V]).value
	} else {
		return nil
	}
}

func (l *lru[K, V]) Set(k K, value *V) {
	if v, ok := l.hash[k]; ok {
		l.dlList.MoveToFront(v)
		v.Value.(*node[K, V]).value = value
	} else {
		l.size++
		if l.size > l.capacity {
			last := l.dlList.Back()
			key := last.Value.(*node[K, V]).key
			delete(l.hash, key)
			l.dlList.Remove(last)
			l.size--
		}
		el := l.dlList.PushFront(&node[K, V]{
			key: k, value: value,
		})
		l.hash[k] = el
	}
}

type LRUCache struct {
	cache *lru[int, int]
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		cache: newLRU[int, int](capacity),
	}
}

func (this *LRUCache) Get(key int) int {
	if v := this.cache.Get(key); v != nil {
		return *v
	} else {
		return -1
	}
}

func (this *LRUCache) Put(key int, value int) {
	this.cache.Set(key, &value)
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
