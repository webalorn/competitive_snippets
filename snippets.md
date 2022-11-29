## Code

TODO : split string, fft, see ulm book

- **Utility**
  - `includes`
  - `main_default`
  - `islocal` *(compile with -Don_local)*
  - `cout_anything` (for debugging purposes)
  - `string_utility` (`split`, `trim`, `ltrim`, `rtrim`)
  - `usaco` *Read and write in files*
  - `sync_false`
  - `testsfor` *(read the number of tests and loop over it)*
- **C++ shortcurts**
  - `foru` *(itérer ascendant)*
  - `ford` *(itérer descendant)*
  - `forel` *(itérer dans une structure)*
  - `foriel` *(itérer indice et élément (like `enumerate` in python))*
  - `infop` *(opérateur < rapidement)*
  - `lambda`
  - `vv` *(`vector<int>` par défaut)*
  - `ssize` *(int)___.size()*
  - `reresize` *resize(0) ; resize(n) *(or `.assign(n, val)`)*
  - `2pb`
  - `rint`, `rvar`
  - `print` *cout with spaces and newline*
- **Definitions**
  - `def_consts`
  - `def_types`
- **Contest-specific templates**
  - `battleDev_main`

## Tools

-   `tool_reindexer`

## Structs

- `str_graph`
- `str_bigint`
- `str_pos` *(Pos et moves)*
- `str_grid` *(Read and store grid, functions on grids)*
- `str_segtree`
    - `segtree_template`
    - `segtree_max`, `segtree_sum`

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
    - `algo_flow` , `algo_flow_sparse`
    - `algo_min_cut`, `algo_min_cut_sparse`
    - `algo_min_cost_max_flow` , `algo_min_cost_max_flow_sparse` , `algo_min_cost_max_flow_slower`
    - `algo_min_cost_max_flow_negative` // Works with negative costs 
    - `algo_max_matching`
- **Maths**
  - `math_usual` *// pgcd, ppcm, factorielle, base conversion
  - `math_primes` *// genNPrimes, genPrimesUnder*
- **Geometry**
    - $x*y=||x||.||y||.cos(x,y)$, $det(x,y)=||x||.||y||.sin(x,y)$
        - Composante colinéaire à $x$ : $\frac{x*y}{||x||}$. Orthogonale : $\frac{det(x,y)}{||x||}$
    - `geo_base` (Vect and base functions. Set vint = double if you want non-integer coords)
    - `geo_rects` (To work with rectangles)
    - `geo_segs` (To work with segments and lines)
    - `geo_convex_hull.cpp`
    - `geo_shapes` // borderToSegs, arePointsInArea, ...

## C++ useful functions

  - `[string].substr(start, size)` *// Get a substring*
  - `to_string(value)` *// something to string*
  - `stoi(string, pos=0, base=10)` *// string to int*
  - Cout with 0 at the begening: ```cout.fill('0’); cout.width(4);```
  - ```std::fixed``` puis ```setprecision(k)```
  - `priority_queue<int, std::vector<int>, decltype(comp)> `
  - `atan2`



# Python

## Code

-   `mainDefault`, `mainLarg` `mainShort`, `mainMini`, `mdfMain`
-   `utilPoints` (vectors, points as tuples)
-   `utilMath` (primes, pgcd, ppcm, fact, binom, is_palindrom)
-   `utilCollections` (with `argmin`, `argmax`, and for dicts, and uchain, l2str, `reindexer`)
-   `utilSearch` (upper_bound, lower_bound, range, is_in_sorted)
-   `utilCombi` (next_permutation, get_permuts)
-   Short names:
    -   `cin`, `rcin`, `icin`,`micin` `cout`
    -   `rr`, `rint`,`rmint`, `lrmint`, `fprint`
    -   `rfor`
    -   (`read_print`)
    -   `struct` (With nammed tuple. Set with `a = a._replace(x=11, z=a.y)`)

## Structures

May be required by some algorithms

-   `str_heap` 
-   `str_graph`

## Algo

-   General
    -   `algo_union_find`
    -   `algo_dicho`
    -   `algo_merge_sort`
    -   `algo_cumul`
    -   `algo_dicho`
-   Graph
    -   `algo_dfs`
    -   `algo_bfs`
    -   `algo_dij` (Dijkstra, à améliorer)
    -   `algo_bellman_ford`
-   Structures
    -   `str_cartesian_tree` (and `str_cartesian_tree_extras`)
    -   `str_heap`
    -   `str_graph`
    -   `str_deque`

## Python useful functions

-   `{0:.2f}'.format(x)`, `round(x, 2)`
-   `map(f, l)`, `filter(f, l)`, `reduce(f, l, start)`
-   `deque.pop()`, `deque.popleft()`, `deque.append()`, `deque.appendleft`
-   `dict.keys()`, `dict.items()`, `dict.pop(key)`, `dict.values()`
-   `set.add(v)`, `s.remove(v)`
-   `accumulate(list, [func, initial=None])`, `chain(list1, list2, ...)`
-   `permutations(list)`, `combinations(list)`, `product(list1, list2, ...)`