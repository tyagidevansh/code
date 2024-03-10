def generate(numRows):
    if numRows == 0:
        return []
    if numRows == 1:
        return [[1]]
    
    prevRows = generate(numRows-1)
    newRow = [1] * numRows
    
    for i in range(1, numRows-1):
        newRow[i] = prevRows[-1][i-1] + prevRows[-1][i]
    
    prevRows.append(newRow)
    return prevRows

def generate2(numRows):
    res = []
    if numRows == 0:
        return res
    
    first_row = [1]
    res.append(first_row)
    
    for i in range(1, numRows):
        prev_row = res[i-1]
        curr_row = [1]
        
        for j in range(1, i):
            curr_row.append(prev_row[j-1] + prev_row[j])
        
        curr_row.append(1)
        res.append(curr_row)
    return res 

generate(4)