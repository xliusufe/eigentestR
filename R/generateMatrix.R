# list of functions which are used by R codes.
generateMatrix <- function(n){
  if(n<=0){
    stop("n must be a positive integer!")
    return(0)    
  }
  else{
    result = .Call("ExportsMatrixPlus", as.integer(n), PACKAGE = "eigentest")
    #result = .Call("ExportsMatrixPlus",as.integer(n))
    M = matrix(result$M,n,n)
    return(M)
  }
}




