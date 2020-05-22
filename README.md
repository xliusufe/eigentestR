# eigentest

A demo of R-package including the `C++` library `EIGEN` without assistence of `Rcpp`.

# Installation

    #install Rtools 3.5 (http://cran.r-project.org/bin/windows/Rtools)
    #install.packages("devtools")
    library(devtools)
    install_github("xliusufe/eigentestR")

# Usage

   - [x] [eigentest-manual](https://github.com/xliusufe/eigentestR/blob/master/inst/eigentest-manual.pdf) ------------ Details of the usage of the package.
# Example

    library(eigentest)
	d = 4
	M = generateMatrix(d)
	M
 
# Development
The R-package is developed by Xu Liu (liu.xu@sufe.edu.cn).
