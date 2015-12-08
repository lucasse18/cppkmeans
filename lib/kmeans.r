options(error = recover)

yykmeans <- function(dat, K) {
    N = nrow(dat)
    dat = as.matrix(dat)
    lb = rep(0, N)
    ub = rep(0, N)
    delta = rep(0, K)
    cluster = rep(-1, N)
    centers = data.frame(matrix(0, ncol=ncol(dat), nrow = K))
    colnames(centers) <- colnames(dat)
    centers = as.matrix(centers)
    Ncenters = rep(0,K)

    # inicializacao
    tmpcenter = sample(1:N, K)
    print(tmpcenter)
    #tmpcenter =c(18,70,101)
    for (c in 1:K) {
        centers[c,] = dat[tmpcenter[c],]
    }

    newcenters = matrix(0, ncol=ncol(dat), nrow = K)
    # primeiro passo de atualizacao
    for (x in 1:N) {
        dists = rep(0, K)
        for (c in 1:K) {
            dif = centers[c,]-dat[x,]
            dists[c] = sqrt(dif%*%dif)
        }
        cluster[x] = which.min(dists)
        Ncenters[cluster[x]] = Ncenters[cluster[x]] + 1
        newcenters[cluster[x],] = newcenters[cluster[x],]+dat[x,]
        ub[x] = min(dists)
        dists[which.min(dists)] = Inf
        lb[x] = min(dists)
    } #
    for (c in 1:K) {
        newcenters[c,] = newcenters[c,]/Ncenters[c]
        dif = centers[c,] - newcenters[c,]
        delta[c] = sqrt(dif%*%dif)
    }
    centers = newcenters

    # iteracao
    mudou = T
    iteracoes = 0
    evitou = 0
    while (mudou && iteracoes < 100) {
        mudou = F
        iteracoes = iteracoes + 1

        newcenters = matrix(0, ncol=ncol(dat), nrow = K)

        for (x in 1:N) {
            #update upper bound
            ub[x] = ub[x] + delta[c]
            #update lower bound
            lb[x] = lb[x] - max(delta)

            if (ub[x] > lb[x]) {
                for (c in 1:K) {
                    dif = centers[c,]-dat[x,]
                    dists[c] = sqrt(dif%*%dif)
                }
                if (which.min(dists) != cluster[x]) {
                    mudou = T
                    cluster[x] = which.min(dists)
                }
            } else {
                evitou = evitou +1
            }
            newcenters[cluster[x],] = newcenters[cluster[x],] + dat[x,]
        }
        for (c in 1:K) {
            newcenters[c,] = newcenters[c,]/sum(cluster==c)
            dif = centers[c,] - newcenters[c,]
            delta[c] = sqrt(dif%*%dif)
        }
        centers = newcenters
    }
    if (iteracoes == 100)
        cat("warning: iteracoes == 100\n")

    res = c()
    res$delta = delta
    res$centers = centers
    res$cluster = cluster
    res$lb = lb
    res$ub = ub
    res$iteracoes = iteracoes
    res$evitou = evitou
    res
}
