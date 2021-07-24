" My vim config

set nocompatible             " be iMproved, required
set number
set autochdir				 " start at current directory file
set noshowmode
set cursorline
set laststatus=2
set tabstop=4
set shiftwidth=4
set encoding=UTF-8
set termguicolors
filetype off                 " required

set rtp+=~/.vim/bundle/Vundle.vim

call vundle#begin()

Plugin 'VundleVim/Vundle.vim'

" Add plugins here

Plugin 'preservim/nerdtree'
Plugin 'preservim/nerdcommenter'
Plugin 'itchyny/lightline.vim'
Plugin 'ayu-theme/ayu-vim'
Plugin 'sheerun/vim-polyglot'
Plugin 'ap/vim-css-color'
Plugin 'Yggdroot/indentLine'
Plugin 'arcticicestudio/nord-vim'
"Install coc.vim

call vundle#end()            " required

filetype plugin indent on    " required

colorscheme nord

nnoremap <silent> <C-t> :NERDTreeToggle <CR>

"let ayucolor="mirage"   " for dark version of theme
"colorscheme ayu
let g:lightline = {
      \ 'colorscheme': 'nord'
      \ }

