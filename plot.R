print('Ploting ....')

jpeg('rplot.jpg')

args = commandArgs(trailingOnly=TRUE)

# test if there is at least one argument: if not, return an error
if (length(args)==0) {
    stop("At least one argument must be supplied (input file).n", call.=FALSE)
}

x_1 <- 0.7
y_1 <- 0.7
x_2 <- -0.98
y_2 <- 0.17

x_1 <- as.numeric(args[1])
y_1 <- as.numeric(args[2])
x_2 <- as.numeric(args[3])
y_2 <- as.numeric(args[4])

print(x_1)
print(y_1)
print(x_2)
print(y_2)

plot(c(-1,1),c(-1,1))

arrows(0,0,x_1,y_1,lwd=3)
arrows(0,0,x_2,y_2,lwd=3)
arrows(0,0,0,-1,lwd=3)

dev.off()

q()
