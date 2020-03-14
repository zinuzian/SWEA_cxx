/*
크루스칼

A = 0
for vertex v in G.V
    make_set(v)

    G.E에 포함된 간선들을 가중치 w에 의해 정렬


    for 가중치가 가장 낮은 간선 (u,v), elem of G.E 선택(n-1개)
        if find_set(U) != find_set(v)
             A = A U {(u,v)}
             Union(u, v)

    return A


*/