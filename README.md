# Mini-Individual-Project
 
This is the implementation of the COMP3011 Mini Individual Project.

# There are four directories:
 exact: source data
 ILP: the inequalities derived from the CEP
 ILP_ans: the ILP solution
 result: the result graphs after applying the ILP solution
 
# There are three source code files for the algorithm:
 step1_convert_CEP_to_ILP.cpp: convert the source data into ILP inequalities (corresponding to section 4 step 1 in report)
 step2_ILP_solver.m: use a MATLAB function 'intlinprog' to solve the drived ILP (corresponding to section 4 step 2 in report)
 step3_check_ILP_ans.cpp: check apply the ILP solution back to the graph and output the result graph

# Besides, there are two python programs for graph visualization:
 visualization_init_graph.py : visualize the initial graph
 visualization_result_graph.py: visualize the graph after implementing the algorithm
 
# Workflow of the implementation:
run step1_convert_CEP_to_ILP.cpp, input: exact, output: ILP
run step2_ILP_solver.m, input: ILP, output: ILP_ans
run step3_check_ILP_ans.cpp, input: ILP_ans, output: result
run visualization_init_graph.py, input: exact, output: a graph
run visualization_result_graph.py, input: result, output: a graph
