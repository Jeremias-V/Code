" My vim config

set nocompatible              " be iMproved, required
set number
set autochdir " start at current directory file
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/vim-colors-solarized
set rtp+=~/.vim/bundle/Vundle.vim


call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" Add plugins here

Plugin 'vim-syntastic/syntastic'
Plugin 'tomasiser/vim-code-dark'
Plugin 'tpope/vim-fugitive'
Plugin 'itchyny/lightline.vim'
Plugin 'preservim/nerdtree'
Plugin 'preservim/nerdcommenter'

call vundle#end()            " required

filetype plugin indent on    " required

nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>
set background=dark
set t_Co=256
set t_ut=
colorscheme codedark
