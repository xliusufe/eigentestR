\name{generateMatrix}
\alias{generateMatrix}
\docType{methods}
\title{
R package including the C++ library "EIGEN" 
}
\description{
R package including the C++ library "EIGEN" 
}
\usage{
generateMatrix(n)
}

\arguments{
  \item{n}{The dimension of the outputted matrix.}
}

\value{
  \item{M}{The matrix produced randomly.}
}

\examples{
  n = 4
  M = generateMatrix(n)
  M
}
