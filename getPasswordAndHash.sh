#!/bin/bash

PASSWORD=$(pwgen $1 1) ; echo $PASSWORD ; echo -n $PASSWORD | openssl sha256
