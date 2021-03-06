% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/class_modlist.R
\name{modlist}
\alias{modlist}
\title{Create a modlist object.}
\usage{
modlist(project = ".", soloc = tempdir(), prefix = "",
  pattern = paste0(prefix, "*\\\\.cpp$"), index_file = "MODLIST")
}
\arguments{
\item{project}{file path to models}

\item{soloc}{directory where the models will be built}

\item{prefix}{leading tag for models to process}

\item{pattern}{a regular expression for models to get}

\item{index_file}{name of file to look for registered models}
}
\description{
Create a modlist object.
}
