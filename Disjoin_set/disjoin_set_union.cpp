#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;
    int numComponents;
public:
    // Constructor to initialize the disjoint set with 'n' elements
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        numComponents = n;
        
        // Initially, each element is its own parent
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // Find operation with path compression
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    // Union operation with union by rank
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX == rootY) {
            return false; // Already in the same component
        }
        
        // Union by rank
        if(rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if(rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        numComponents--;
        return true;
    }
    
    // Check if two elements are connected
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    
    // Get number of connected components
    int getNumComponents() {
        return numComponents;
    }
    
    // Get the root of an element
    int getRoot(int x) {
        return find(x);
    }
    
    // Count the size of the component containing x
    int componentSize(int x) {
        // This requires a slightly different implementation to track sizes
        // For now, just return 1 as a placeholder
        return 1;
    }
};

int main() {
    // Example usage of Disjoint Set Union
    cout << "=== Disjoint Set Union Implementation ===" << endl;
    int n = 6;
    DisjointSet dsu(n);
    
    cout << "Initial number of components: " << dsu.getNumComponents() << endl;
    
    // Perform some union operations
    cout << "\nPerforming union(0, 1)" << endl;
    dsu.unite(0, 1);
    cout << "Number of components after union(0, 1): " << dsu.getNumComponents() << endl;
    
    cout << "Performing union(1, 2)" << endl;
    dsu.unite(1, 2);
    cout << "Number of components after union(1, 2): " << dsu.getNumComponents() << endl;
    
    cout << "Performing union(3, 4)" << endl;
    dsu.unite(3, 4);
    cout << "Number of components after union(3, 4): " << dsu.getNumComponents() << endl;
    
    // Check connectivity
    cout << "\n--- Connectivity Checks ---" << endl;
    cout << "Is 0 connected to 2? " << (dsu.isConnected(0, 2) ? "Yes" : "No") << endl;
    cout << "Is 0 connected to 4? " << (dsu.isConnected(0, 4) ? "Yes" : "No") << endl;
    cout << "Is 1 connected to 3? " << (dsu.isConnected(1, 3) ? "Yes" : "No") << endl;
    cout << "Is 3 connected to 5? " << (dsu.isConnected(3, 5) ? "Yes" : "No") << endl;
    
    // More union operations
    cout << "\nPerforming union(0, 5)" << endl;
    dsu.unite(0, 5);
    cout << "Number of components after union(0, 5): " << dsu.getNumComponents() << endl;
    
    // Final connectivity checks
    cout << "\n--- Final Connectivity Checks ---" << endl;
    cout << "Is 2 connected to 5? " << (dsu.isConnected(2, 5) ? "Yes" : "No") << endl;
    cout << "Is 1 connected to 5? " << (dsu.isConnected(1, 5) ? "Yes" : "No") << endl;
    cout << "Is 3 connected to 4? " << (dsu.isConnected(3, 4) ? "Yes" : "No") << endl;
    
    // Try to unite already connected elements
    cout << "\n--- Union Operations on Connected Elements ---" << endl;
    cout << "Trying to unite 0 and 2 (already connected): " << (dsu.unite(0, 2) ? "Success" : "Failed - already connected") << endl;
    cout << "Trying to unite 3 and 4 (already connected): " << (dsu.unite(3, 4) ? "Success" : "Failed - already connected") << endl;
    
    cout << "\nFinal number of components: " << dsu.getNumComponents() << endl;
    
    cout << "\n--- Root Elements ---" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Element " << i << " belongs to component rooted at: " << dsu.getRoot(i) << endl;
    }
    
    cout << "\nProgram completed successfully!" << endl;
    return 0;
}