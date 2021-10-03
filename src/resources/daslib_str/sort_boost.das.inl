//
// AUTO-GENERATED FILE - DO NOT EDIT!!
//

"options indenting = 4\n"
"options no_unused_block_arguments = false\n"
"options no_unused_function_arguments = false\n"
"\n"
"module sort_boost shared private\n"
"\n"
"require daslib/ast_boost\n"
"require daslib/array_boost public\n"
"\n"
"[call_macro(name=\"qsort\")]\n"
"class QsortMacro : AstCallMacro\n"
"    def override visit ( prog:ProgramPtr; mod:Module?; var expr:smart_ptr<ExprCa"
"llMacro> ) : ExpressionPtr\n"
"        if expr.arguments.length != 2\n"
"            macro_error(prog,expr.at,\"expecting qsort(value, block)\")\n"
"            return [[ExpressionPtr]]\n"
"        if expr.arguments[0]._type==null || expr.arguments[1]._type==null\n"
"            return [[ExpressionPtr]]\n"
"        // todo: verify correct block type?\n"
"        if expr.arguments[1]._type.baseType != Type tBlock\n"
"            macro_error(prog,expr.at,\"expecting 2nd argument to be block(<a,b:au"
"to(TT)>:bool))\")\n"
"            return [[ExpressionPtr]]\n"
"        if expr.arguments[0]._type.dim.length != 0 || expr.arguments[0]._type.ba"
"seType==Type tArray\n"
"            var call <- new [[ExprCall() name:=\"sort\", at=expr.at]]\n"
"            emplace_new(call.arguments) <| clone_expression(expr.arguments[0])\n"
"            emplace_new(call.arguments) <| clone_expression(expr.arguments[1])\n"
"            return <- call\n"
"        elif expr.arguments[0]._type.baseType==Type tHandle\n"
"            var call <- new [[ExprCall() name:=\"sort\", at=expr.at]]\n"
"            var tsa <- new [[ExprCall() name:=\"temp_array\", at=expr.at]]\n"
"            emplace_new(tsa.arguments) <| clone_expression(expr.arguments[0])\n"
"            tsa.genFlags |= ExprGenFlags alwaysSafe\n"
"            emplace(call.arguments,tsa)\n"
"            emplace_new(call.arguments) <| clone_expression(expr.arguments[1])\n"
"            return <- call\n"
"        else\n"
"            macro_error(prog,expr.at,\"can only qsort [], array, or handled vecto"
"r\")\n"
"            return [[ExpressionPtr]]\n"
"\n"
