#ifndef CURS8_MULTIMAP_H
#define CURS8_MULTIMAP_H
#include <iostream>
#include <vector>
using namespace std;
template <class Key, class Value>
class Multimap {
public:
    template <class K, class V>
    class MapNode {
    public:
        K key;
        V value;
        MapNode<K,V>* next;
        MapNode(K key, V value) : key(key), value(value){ this->next= nullptr;}
    };
    template<class V>
    class ListNode {
    public:
        V info;
        ListNode<V> *next;
        ListNode(V info, ListNode<V> *next) : info(info), next(next) {}
        ListNode(V info) : info(info) { next = nullptr; }
    };
    int size;
    MapNode<Key,ListNode<Value>*>* first;

    MapNode<Key, ListNode<Value>*>* searchAdress(Key k){
        /// Returns the adress of certain mapnode by it's key.
        if(this->size == 0) return nullptr;
        MapNode<Key, ListNode<Value>*>* p = first;
        while(p->next != nullptr){
            if(p->key == k) return p;
            p = p->next;
        }
        return p;
    }


public:
    Multimap(){
        this->first = nullptr;
        this->size = 0;
    }
    void put(Key key, Value value){
        /// Inserts a node with given key and value.
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);

        if(poz == nullptr){

            this->first = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
            this->size++;
        }else{
            if(poz->key == key){
                ListNode<Value>* node = new ListNode<Value>(value, poz->value);
                poz->value = node;
            }else{
                poz->next = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
                this->size++;
            }
        }
    }

    vector<Value> remove(Key key){
        /// Deletes a mapnode with given key.
        /// Returns a vector with the deleted values from key.
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);
        vector<Value> result;

        if(poz != nullptr && poz->key == key){
            MapNode<Key, ListNode<Value>*>* p = first;
            if(poz == first) this->first = poz->next;
            else {
                while(p->next != poz) p = p->next;
                p->next = poz->next;
            };
            while(poz->value != nullptr){
                ListNode<Value>* node = poz->value;
                result.push_back(node->info);
                poz->value = node->next;
                delete node;
            }
            this->size--;
            delete poz;
        }
        return result;
    }

//    template<class K, class V>
//    friend std::ostream & operator<<(std::ostream & os, const Multimap<K, V*> & mm){
//
//    };
template <class V, class K>

vector<V> showValuesForKey(K key) {
        /// Returns a vector with values of a mapnode with certain key.
        vector<V> result;
        if (size == 0) return result;
        MapNode<Key, ListNode<Value> *> *p = first;
            while (p != nullptr) {
                if (p->key == key) {
                    ListNode<Value> *node = p->value;
                    while (node != nullptr) {
                        result.push_back(node->info);
                        node = node->next;
                    }


            }
                p = p->next;
        }


            return result;
        }


};



#endif //CURS8_MULTIMAP_H
