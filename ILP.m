filename1 = 'ILP/';
filename2 = '.txt';
outfilename1 = 'ILP_ans/';

for file = 1:20
    % open the file
    bai = int2str(idivide(file,int32(100)));
    shi = int2str(idivide(mod(file,100),int32(10)));
    ge = int2str(mod(file,int32(10)));
    filename = [filename1, bai, shi, ge, filename2];
    fid = fopen(filename);
    outfilename = [outfilename1, bai, shi, ge, filename2];
    out_fid = fopen(outfilename, 'w');
    
    % set some constants
    Aeq = [];
    beq = [];

    n = fscanf(fid, "%d", 1);
    cols = fscanf(fid, '%d', 1);
    rows = fscanf(fid, '%d', 1);

    % read f
    f = fscanf(fid, "%d", cols);

    % read A
    A = zeros(rows, cols);
    for i = 1:rows
        x = fscanf(fid, '%d', 1);
        y = fscanf(fid, '%d', 1);
        z = fscanf(fid, '%d', 1);
        A(i, x) = 1;
        A(i, y) = 1;
        A(i, z) = -1;
    end
      
    % set b
    b = zeros(rows, 1);
    for i = 1:rows
        b(i, 1) = 1;
    end

    lb = zeros(1, cols);
    ub = ones(1, cols);
    intcon = 1:cols;
    
    x = intlinprog(f, intcon, A, b, Aeq, beq, lb, ub);

    fprintf(out_fid, "%d\n", n);
    fprintf(out_fid, '%d ', x);
    fprintf(out_fid, '\n');

end


 
