//
// AUTO-GENERATED FILE - DO NOT EDIT!!
//

"options indenting = 4\n"
"options no_unused_block_arguments = false\n"
"options no_unused_function_arguments = false\n"
"\n"
"module algorithm shared public\n"
"\n"
"require daslib/array_boost\n"
"require daslib/contracts\n"
"\n"
"def unique ( var a:array<auto(TT)> )\n"
"    var pidx = -1\n"
"    var b : array<TT-const-&>\n"
"    for e,eidx in a,range(length(a))\n"
"        if pidx==-1 || a[pidx]!=e\n"
"            pidx = eidx\n"
"            b |> push_clone(e)\n"
"    return <- b\n"
"\n"
"def sort_unique ( var a : array<auto(TT)> )\n"
"    if empty(a)\n"
"        return\n"
"    sort(a)\n"
"    var b <- unique(a)\n"
"    delete a\n"
"    a <- b\n"
"\n"
"def reverse ( var a:array<auto> )\n"
"    let l = length(a)\n"
"    let half = l/2\n"
"    let lm1 = l-1\n"
"    for i in range(half)\n"
"        swap(a[i], a[lm1-i])\n"
"\n"
"def combine ( a,b:array<auto(TT)> )\n"
"    var c : array<TT>\n"
"    reserve(c, length(a) + length(b))\n"
"    for t in a\n"
"        c |> push(t)\n"
"    for t in b\n"
"        c |> push(t)\n"
"    return <- c\n"
"\n"
"def lower_bound ( a:array<auto(TT)>; f,l:int; val : TT const-& )\n"
"    assert(f>=0 && f<=l,\"lower bound first out of range\")\n"
"    assert(l>=f && l<=length(a),\"lower bound last out of range\")\n"
"    var count = l - f\n"
"    var first = f\n"
"    while count > 0\n"
"        let step = count / 2\n"
"        let it = first + step\n"
"        if a[it] < val\n"
"            first += step + 1\n"
"            count -= step + 1\n"
"        else\n"
"            count = step\n"
"    return first\n"
"\n"
"def lower_bound ( a:array<auto(TT)>; val : TT const-& )\n"
"    return lower_bound(a,0,length(a),val)\n"
"\n"
"def lower_bound ( a:array<auto(TT)>; f, l : int; value:TT const-&; less : block<"
"(a, b:TT const-&):bool> )\n"
"    assert(f>=0 && f<=l,\"lower bound first out of range\")\n"
"    assert(l>=f && l<=length(a),\"lower bound last out of range\")\n"
"    var count = l - f\n"
"    var first = f\n"
"    while count > 0\n"
"        let step = count / 2\n"
"        let it = first + step\n"
"        if invoke(less,a[it],value)\n"
"            first += step + 1\n"
"            count -= step + 1\n"
"        else\n"
"            count = step\n"
"    return first\n"
"\n"
"def lower_bound ( a:array<auto(TT)>; value:TT const-&; less : block<(a, b:TT con"
"st-&):bool> )\n"
"    return lower_bound(a, 0, length(a), value, less )\n"
"\n"
"def binary_search ( a:array<auto(TT)>; val : TT const-& )\n"
"    let first = lower_bound(a, val)\n"
"    return (first!=length(a)) && (!(val<a[first]))\n"
"\n"
"def binary_search ( a:array<auto(TT)>; f, last : int; val : TT const-& )\n"
"    let first = lower_bound(a, f, last, val)\n"
"    return (first!=last) && (!(val<a[first]))\n"
"\n"
"def binary_search ( a:array<auto(TT)>; val : TT const-&; less : block<(a, b:TT c"
"onst-&):bool> )\n"
"    let first = lower_bound(a, val, less)\n"
"    let last = length(a)\n"
"    return (first!=last) && (!invoke(less,val,a[first]))\n"
"\n"
"def binary_search ( a:array<auto(TT)>; f, last : int; val : TT const-&; less : b"
"lock<(a, b:TT const-&):bool> )\n"
"    let first = lower_bound(a, f, last, val, less)\n"
"    return (first!=last) && (!invoke(less,val,a[first]))\n"
"\n"
"// now for all the other types\n"
"\n"
"[expect_any_array(a)]\n"
"def reverse ( var a )\n"
"    unsafe\n"
"        reverse(temp_array(a))\n"
"\n"
"[expect_any_array(a)]\n"
"def combine ( a,b )\n"
"    unsafe\n"
"        return combine(temp_array(a),temp_array(b))\n"
"\n"
"[expect_any_array(a)]\n"
"def lower_bound ( a; f,l:int; val )\n"
"    static_if typeinfo(stripped_typename a[0]) != typeinfo(stripped_typename val"
")\n"
"        concept_assert(false, \"value type {typeinfo(stripped_typename val)} shou"
"ld be the same as array {typeinfo(stripped_typename a)} element type {typeinfo(s"
"tripped_typename a[0])}\")\n"
"        return -1\n"
"    else\n"
"        unsafe\n"
"            return lower_bound(temp_array(a), f,l, val)\n"
"\n"
"[expect_any_array(a)]\n"
"def lower_bound ( a; val )\n"
"    static_if typeinfo(stripped_typename a[0]) != typeinfo(stripped_typename val"
")\n"
"        concept_assert(false, \"value type {typeinfo(stripped_typename val)} shou"
"ld be the same as array {typeinfo(stripped_typename a)} element type {typeinfo(s"
"tripped_typename a[0])}\")\n"
"        return -1\n"
"    else\n"
"        unsafe\n"
"            return lower_bound(temp_array(a), val)\n"
"\n"
"[expect_any_array(a)]\n"
"def lower_bound ( a; f, l : int; value:auto(TT); less : block<(a, b:TT const-&):"
"bool> )\n"
"    static_if typeinfo(stripped_typename a[0]) != typeinfo(stripped_typename val"
")\n"
"        concept_assert(false, \"value type {typeinfo(stripped_typename val)} shou"
"ld be the same as array {typeinfo(stripped_typename a)} element type {typeinfo(s"
"tripped_typename a[0])}\")\n"
"        return -1\n"
"    else\n"
"        unsafe\n"
"            return lower_bound(temp_array(a), f, l, value, less)\n"
"\n"
"[expect_any_array(a)]\n"
"def lower_bound ( a; value:auto(TT); less : block<(a, b:TT const-&):bool> )\n"
"    static_if typeinfo(stripped_typename a[0]) != typeinfo(stripped_typename val"
")\n"
"        concept_assert(false, \"value type {typeinfo(stripped_typename val)} shou"
"ld be the same as array {typeinfo(stripped_typename a)} element type {typeinfo(s"
"tripped_typename a[0])}\")\n"
"        return -1\n"
"    else\n"
"        unsafe\n"
"            return lower_bound(temp_array(a), value, less)\n"
"\n"
"[expect_any_array(a)]\n"
"def binary_search ( a; val )\n"
"    static_if typeinfo(stripped_typename a[0]) != typeinfo(stripped_typename val"
")\n"
"        concept_assert(false, \"value type {typeinfo(stripped_typename val)} shou"
"ld be the same as array {typeinfo(stripped_typename a)} element type {typeinfo(s"
"tripped_typename a[0])}\")\n"
"        return -1\n"
"    else\n"
"        unsafe\n"
"            return binary_search(temp_array(a), val)\n"
"\n"
"[expect_any_array(a)]\n"
"def binary_search ( a; f, last : int; val )\n"
"    static_if typeinfo(stripped_typename a[0]) != typeinfo(stripped_typename val"
")\n"
"        concept_assert(false, \"value type {typeinfo(stripped_typename val)} shou"
"ld be the same as array {typeinfo(stripped_typename a)} element type {typeinfo(s"
"tripped_typename a[0])}\")\n"
"        return -1\n"
"    else\n"
"        unsafe\n"
"            return binary_search(temp_array(a), f, last, val)\n"
"\n"
"[expect_any_array(a)]\n"
"def binary_search ( a; val : auto(TT); less : block<(a, b:TT const-&):bool> )\n"
"    static_if typeinfo(stripped_typename a[0]) != typeinfo(stripped_typename val"
")\n"
"        concept_assert(false, \"value type {typeinfo(stripped_typename val)} shou"
"ld be the same as array {typeinfo(stripped_typename a)} element type {typeinfo(s"
"tripped_typename a[0])}\")\n"
"        return -1\n"
"    else\n"
"        unsafe\n"
"            return binary_search(temp_array(a), val, less)\n"
"\n"
"[expect_any_array(a)]\n"
"def binary_search ( a; f, last : int; val : auto(TT); less : block<(a, b:TT cons"
"t-&):bool> )\n"
"    static_if typeinfo(stripped_typename a[0]) != typeinfo(stripped_typename val"
")\n"
"        concept_assert(false, \"value type {typeinfo(stripped_typename val)} shou"
"ld be the same as array {typeinfo(stripped_typename a)} element type {typeinfo(s"
"tripped_typename a[0])}\")\n"
"        return -1\n"
"    else\n"
"        unsafe\n"
"            return binary_search(temp_array(a), f, last, val, less)\n"
