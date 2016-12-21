% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/chain.R
\docType{methods}
\name{Req}
\alias{Req}
\alias{Req,mrgmod-method}
\alias{req}
\alias{req,mrgmod-method}
\title{Set the \code{Request} argument for \code{mrgsim}.}
\usage{
Req(x, ...)

\S4method{Req}{mrgmod}(x, ...)

req(x, ...)

\S4method{req}{mrgmod}(x, ...)
}
\arguments{
\item{x}{model object}

\item{...}{unquoted names of compartments or tabled items}
}
\description{
Set the \code{Request} argument for \code{mrgsim}.
}
\examples{
mod <- mrgsolve:::house()

mod \%>\% Req(CP,RESP) \%>\% ev(amt=1000) \%>\%  mrgsim

}
