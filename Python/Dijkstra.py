from typing import List
#
#    朴素迪杰斯特拉 dijkstra
#    单源最短路径，source为源点，dis为到各个点的最短路
#    时间复杂度O(n^2)
#

inf = int(1e9+5)

def dijkstra(roads: List[List[int]], n: int, source: int):
    m = [ [ inf ] * n for _ in range(n) ]
    for [ x, y, v ] in roads:
        m[ x ][ y ] = v
        m[ y ][ x ] = v # 有向图去掉该行
    
    dist , vis = [ inf ] * n, [ False ] * n

    for i in range( n ):
            dist[i] = m[source][i]
    dist[source] , vis[source] = 0, True
    for _ in range( n - 1):
        node = -1
        for i in range( n ):
            if not vis[i] and ( node == -1 or dist[node] > dist[i] ):
                node = i # 更新 未被访问过，且距离 source 最短的点
        if node == -1: # 如果未找到，说明已经找到所有的源点能到达的点
            break
        for i in range( n ):
            dist[i] = min( dist[i] , dist[node] + m[node][i] ) # 更新 其他点的最短路
        vis[node] = 1 # 标记该点已访问

    return dist