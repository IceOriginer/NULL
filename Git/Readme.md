了解Git object, 如blob、tree、commit等

知道git reset --soft、git reset、git rest --hard的区别

听说过git reflog

git将文本信息通过SHA1哈希算法进行编码，得到git中的唯一ID。

git储存采用的是键值对， ID->内容

HEAD、分支、普通的Tag可以简单的理解成是一个指针，指向对应commit的SHA1的值

git object包括以下几种类型：
* blob 文件内容
* tree 目录结构、文件权限、文件名
* commit 上一个commit的哈希值，这一次提交对应的快照、作者、提交的信息
* refs HAED、分支、Tag （指针）

前面三种一旦创建就不能变更

为什么要把文件的权限和文件名储存在Tree object里面而不是Blob object中呢？
如果要更改一个文件的文件名，即使文件的内容没有发生变更，git都会重新生成一份新的文件出来。但是如果储存在一个Tree object中的话，只需要新建一个Tree object即可，一般来说一个Blob object会比Tree object大很多，因为Blob object中存储一个文件的具体内容，而Tree object只是当前的目录结构。文件内容没有发生变化，所以对应的哈希值是没有发生变化的，可以复用。

GIT的三个分区及变更历史的形成

工作目录

索引 Index

git仓库


每次commit，Git储存的是全新的文件快照还是储存文件的变更部分
全新的文件快照

当git文件太大的时候，可以采用git命令对相似的文件进行压缩

git怎么保证历史记录不可篡改？
git和区块链的数据结构非常相似，两者都是基于哈希树和分布式。文件一旦发生更改，对应的哈希值就会出现变动，tree object对应的哈希值也会变动，对应commit的节点的哈希值也会发生变动，commit节点之后的所有的节点的哈希值都会发生变动。

GIT实用技巧

不小心删了分支
如：git reset --hard，git rebase

git reflog 时光机
版本控制的版本控制，其它的git object在创建之后都是不可被修改的，但是分支之类的都是一直在变更的，所有的变更记录都是被git reflog所记录下来了。因此如果不小删除了一个分支，可以通过git reflog找到那次commit之前的那个commit记录，然后git reset过去。

如何获得一个干净的工作空间
git reset --hard HEAD 或 git checkout -f
git clean -df
不过尽量不要使用，会删除git记录，并且没办法恢复

推荐使用: git stash push [-u | --include-untracked]
可以获得一个干净的空间，并且可以回到之前的样子

从Git历史中删除一个文件
敏感信息（私钥，内网ip等）
不需要版本控制的超大文件

git filter-branch --tree-filter 'rm -f passsword.txt' HEAD
它会将每一个commit拿出来，然后执行命令中的`rm -f passsword.txt`这一句，执行完成之后再重新commit回去。在执行这个命令之前，一定要保证所有人的代码都已经提交了，因为这个命令执行之后将所有commit节点的哈希值进行修改，如果有人没有提交代码，那么后面代码融合会出现很大的问题。

git command --amend
用于上一次commit之后，发现commit信息写错了，那么你就需要git reset，然后重新commit，但是使用上面的命令之后，它会让你重新输入commit信息，同样必须保证你提交的这个commit节点之后没有新的commit产生。

git rebase -i origin/master
可以提供rebase的选项

git show-branch
查看分支

git blame
看每一行代码的最后一次变更

git bisect
二分查找，什么时候出现错误

每一次修改的时候，会产生新的blob object，并且更新索引。当进行commit的时候会重新生成一个tree object.
每一次commit的时候，git会重新创建一个commit节点，并且将当前commit节点指向前一个commit以及新的tree object.



      
             
