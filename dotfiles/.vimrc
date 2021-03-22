" My vim config

set nocompatible              " be iMproved, required
set number
set autochdir " start at current directory file
set cursorline
set tabstop=4
set shiftwidth=4
set encoding=UTF-8
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim

call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" Add plugins here

Plugin 'vim-syntastic/syntastic'
Plugin 'preservim/nerdtree'
Plugin 'preservim/nerdcommenter'
Plugin 'Valloric/YouCompleteMe'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'arcticicestudio/nord-vim'

call vundle#end()            " required

filetype plugin indent on    " required

nnoremap <silent> <C-t> :NERDTreeToggle <CR>
let g:ycm_global_ycm_extra_conf = '/home/wolfx/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
let g:airline_theme='nord'
set completeopt-=preview
colorscheme nord

