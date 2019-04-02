import UIKit


class DSU {
  private var parent: [Int] = []
  private var sz: [Int] = []
  
  init(length: Int) {
      for i in 0..<length {
          self.parent.append(i)
          self.sz.append(1)
      }
  }
  
  private func swap(a: inout Int, b: inout Int) {
      let c = a
      a = b
      b = c
  }
  
  private func findParent(of u: Int) -> Int {
      if (parent[u] == u) {
          return u
      }
      parent[u] = findParent(of: parent[u])
      return parent[u]
  }

  public func isSameSet(_ u: Int, _ v: Int) -> Bool {
      return findParent(of: u) == findParent(of: v)
  }
  
  public func unionSets(_ u: inout Int, _ v: inout Int) {
      u = findParent(of: u)
      v = findParent(of: v)
      if (sz[u] > sz[v]) {
          swap(a: &u, b: &v)
      }
      parent[u] = v
      sz[v] += sz[u]
  }
    
}


let dsu = DSU(length: 4)
var a = 0
var b = 1
var c = 2
var d = 3
dsu.unionSets(&a, &b)
dsu.unionSets(&b, &c)

if (dsu.isSameSet(a, d)) {
    print("In the same set")
} else {
    print("Not in the same set")
}



