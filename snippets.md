## cpp

- **Utility**
  - `includes`
  - `main_default`
  - `islocal` *(compiler avec -Don_local)*
  - `usaco` *// Read and write in files*
  - `sync_false`
- **C++ shortcurts**
  - `foru` *(itérer ascendant)*
  - `ford` *(itérer descendant)*
  - `forel` *(itérer dans une structure)*
- **Definitions**
  - `def_consts`
  - `def_types`
- **Contest-specific templates**
  - `battleDev_main`

## Structs
- `str_graph`
- `str_pos` *(Pos et moves)*
- `str_grid` *(Read and store grid, functions on grids)*

## I/O
- **Read functions**
  - `read_graph`
  - `read_graph_pondere`
  - `read_flow`
  - `read_min_cost_flow`
  - `read_max_matching`
- **Data conversion**
  - `grid_to_flow` *// Convert grid to max flow graph*
  - `grid_to_graph`

## Algo

- **General**
  - `algo_union_find`
  - `algo_dicho` *// Dichotomie*
  - `algo_merge_sort`
- **Graphs** *(requires str_graph)*
  - `algo_contain_cycle`
  - `algo_dfs`
  - `algo_tri_topo`
  - **Shortest path algorithms**
    - `algo_bfs`
    - `algo_remonte_bfs`
    - `algo_dijkstra`
    - `algo_remonte_dijkstra`
    - `algo_bellman_ford`
    - `algo_floyd_warshall`
  - **Flows / max matching**
    - `algo_flow` *// Max flow*
    - `algo_min_cut`
    - `algo_min_cost_max_flow` *// Min cost max flow*
    - `algo_max_matching`
- **Maths**
  - `math_usual` *// pgcd, ppcm, genNPrimes, genPrimesUnder*
  - `math_numerics` *// factorielle, bases convertion, BigInt*

## C++ useful functions

  - `[string].substr(start, size)` *// Get a substring*
  - `to_string(value)` *// something to string*
  - `stoi(string, pos=0, base=10)` *// string to int*
  - Cout with 0 at the begening: ```cout.fill('0’); cout.width(4);```
  - ```std::fixed``` puis ```setprecision(k)```