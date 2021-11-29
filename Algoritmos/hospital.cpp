#include <iostream>
#include <math.h>

using namespace std;
struct Hospital {
    int id = 0;
    int casos = 0;
};

struct Heap {
    Hospital hospital;
    int size = 0;
    int idTotal = 0;
};

Heap* bubbleDown(int position, Heap *H) {
    int left, right, mid;
    Heap aux;
    left = 2*position + 1;
    right = 2*position + 2;
    mid = position;
    if(left < H->size && H[left].hospital.casos >= H[mid].hospital.casos){
        mid = left;
    }
    if(right < H->size && H[right].hospital.casos >= H[mid].hospital.casos){
        mid = right;
    }
    if(mid != position){
        aux.hospital = H[mid].hospital;
        H[mid].hospital = H[position].hospital;
        H[position].hospital = aux.hospital;
        return bubbleDown(mid, H);
    }
    return H;
}

Heap* buildHeap(int size, Heap *heap) {
    int cont;
    for(cont = floor(size/2) - 1; cont >= 0; cont--){
        bubbleDown(cont, heap);
    }
    return heap;
}

Heap* heapExtract(int id, Heap *heap) {
    Heap aux;
    aux.hospital = heap[id].hospital;
    heap[id].hospital = heap[heap->size-1].hospital;
    heap[heap->size-1].hospital = aux.hospital;
    heap->size--;
    bubbleDown(id, heap);
    return heap;
}

void heapSort(Heap* heap, int id, Heap* hospital) {
    int contador = hospital->size;
    while(contador > 1){
        heapExtract(id, heap);
        contador--;
    }
}

Heap* bubbleUp(int p, Heap *H) {
    int i = p - 1;
    Heap aux;
    while(i > 0 && H[i].hospital.casos >= H[(i-1)/2].hospital.casos){
        aux.hospital = H[i].hospital;
        H[i].hospital = H[(i-1)/2].hospital;
        H[(i-1)/2].hospital = aux.hospital;
        i = (i-1)/2;
    }
    return H;
}

Heap* heapInsert(Heap *heap, int casos) { 
    heap[heap->size-1].hospital.casos = casos;
    heap[heap->size-1].hospital.id = heap->idTotal-1;
    heap = bubbleUp(heap->size, heap);
    return heap;
}

void Del(Heap *heap, int id, int *total) {
    int i;
    i = 0;
    if(heap->size != 0){
        while(i < heap->size){
            if(id == heap[i].hospital.id){
                *total -= heap[i].hospital.casos;
                heap[i].hospital.casos = 0;
                heap = heapExtract(i, heap);
                heap = (Heap*) realloc(heap, heap->size*sizeof(Heap));
                i = heap->size;    
            }
            i++;
        }
        cout << heap[0].hospital.id << " " << heap[0].hospital.casos << endl;
    }
    else{
        cout << "-1 -1" << endl;
        *total = 0;
    }
}

void In(Heap *heap, int id, int casos) {
    int i;
    i = 0;
    while(i < heap->size){
        if(id == heap[i].hospital.id){
        heap[i].hospital.casos += casos;
        cout << heap[i].hospital.casos << endl;
        heap = buildHeap(heap->size , heap);
        i = heap->size;    
        }
        i++;
    }
}

void Out(Heap *heap, int id, int casos) {
    int i;
    i = 0;
    while(i < heap->size){
        if(id == heap[i].hospital.id){
        heap[i].hospital.casos -= casos;
        cout << heap[i].hospital.casos << endl;
        heap = buildHeap(heap->size , heap);
        i = heap->size;
        }
        i++;
    }
}

int Pay(Heap *heap) {
    int R, i, pagaC;

    cin >> pagaC;
    i = 0;
    while (i <= pagaC) {
        if (heap[0].hospital.casos - 1 == 0) {
            heap[0].hospital.casos--;
            R = i;
            cout << R << endl;
            break;
        } else {
            heap[0].hospital.casos--;
        }
        heap = buildHeap(heap->size, heap);
        R = i;
        if(heap[0].hospital.casos == 0){
            R = i;
            cout << R << endl;
        }
        if(i == pagaC){
            cout << pagaC << endl;
            i = pagaC + 2;
        }
        i++;
    }
    return R;
}

int main() {
    int N, i, total = 0, casos = 0, id;
    Heap *heap = NULL;
    string input;

    cin >> N;
    heap = (Heap *)calloc(N, sizeof(Heap));

    for (i = 0; i < N; i++) {
        cin >> casos;
        total += casos;
        heap->idTotal++;
        heap->size++;
        heap = heapInsert(heap, casos);
    }

    while (input != "END") {
        cin >> input;
        if (input == "NEW") {
            cin >> id;
            cin >> casos;
            heap->size++;
            total += casos;
            heap->idTotal++;
            heap = (Heap*) realloc(heap, heap->size*sizeof(Heap));
            heap = heapInsert(heap, casos);
            cout << heap[0].hospital.id << " " << heap[0].hospital.casos << endl;
        }
        else if (input == "DEL") {
            cin >> id;
            Del(heap, id, &total);
        }
        else if (input == "IN") {
            cin >> id >> casos;
            total += casos;
            In(heap, id, casos);
        }
        else if (input == "OUT") {
            cin >> id >> casos;
            total -= casos;
            Out(heap, id, casos);
        }
        else if (input == "PAY") {
            int R = Pay(heap);
            total = total - R;
        }
        else {
            cout << total << endl;
        }
    }
    return 0;
}