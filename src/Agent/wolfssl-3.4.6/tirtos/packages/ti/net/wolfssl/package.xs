/*
 *  ======== package.xs ========
 */

/*
 *  ======== getLibs ========
 *  Contribute wolfSSL library.
 */
function getLibs(prog) 
{
    return ("lib/" + this.$name + ".a" + prog.build.target.suffix);
}
