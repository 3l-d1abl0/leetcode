
<h2><a href="https://www.lintcode.com/problem/787/description">787 · The Maze</a></h2>


<h3>Medium</h3>
<hr>

<div data-h5="false" class="content-wrapper-32rgvmtTEZlJxhYe-SXar4"><div class="sub-title-3tQamyyYH5-VXCEHKrzgsd with-action-3ISUSOCo8G5-PfWWWyKDb9">Description</div><div class="react-markdown react-markdown-2P3YjvgELb5tvqGDu8Rkkt"><p>There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling <code>up</code>, <code>down</code>, <code>left</code> or <code>right</code>, <code>but it won't stop rolling until hitting a wall</code>. When the ball stops, it could choose the next direction.</p>
<p>Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.</p>
<p>The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.</p></div><div data-show="true" class="ant-alert ant-alert-info ant-alert-with-description notice-1ncxxfAmH3X1SpRYMMoH2g"><i aria-label="icon: info-circle" class="anticon anticon-info-circle ant-alert-icon"><svg viewBox="64 64 896 896" focusable="false" class="" data-icon="info-circle" width="1em" height="1em" fill="currentColor" aria-hidden="true"><path d="M512 64C264.6 64 64 264.6 64 512s200.6 448 448 448 448-200.6 448-448S759.4 64 512 64zm0 820c-205.4 0-372-166.6-372-372s166.6-372 372-372 372 166.6 372 372-166.6 372-372 372z"></path><path d="M464 336a48 48 0 1 0 96 0 48 48 0 1 0-96 0zm72 112h-48c-4.4 0-8 3.6-8 8v272c0 4.4 3.6 8 8 8h48c4.4 0 8-3.6 8-8V456c0-4.4-3.6-8-8-8z"></path></svg></i><span class="ant-alert-message"></span><span class="ant-alert-description"><div class="react-markdown react-markdown-2P3YjvgELb5tvqGDu8Rkkt"><p>1.There is only one ball and one destination in the maze.<br>
2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.<br>
3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.<br>
5.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.</p></div></span></div></div>

<div data-h5="false" class="content-wrapper-32rgvmtTEZlJxhYe-SXar4"><div class="sub-title-3tQamyyYH5-VXCEHKrzgsd">Example</div><div class="react-markdown react-markdown-2P3YjvgELb5tvqGDu8Rkkt"><p>Example 1:</p>
<pre><div class="markdown-thumbnail-wrapper" style="height: auto; max-height: unset;"><pre style="display: block; overflow-x: auto; background: rgb(43, 43, 43); color: rgb(248, 248, 242); padding: 0.5em;"><code>Input:
map = 
[
 [<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>],
 [<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>],
 [<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">0</span>],
 [<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">1</span>],
 [<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>]
]
start = [<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">4</span>]
end = [<span style="color: rgb(245, 171, 53);">3</span>,<span style="color: rgb(245, 171, 53);">2</span>]
Output:
<span style="color: rgb(245, 171, 53);">false</span></code></pre></div></pre>
<p>Example 2:</p>
<pre><div class="markdown-thumbnail-wrapper" style="height: auto; max-height: unset;"><pre style="display: block; overflow-x: auto; background: rgb(43, 43, 43); color: rgb(248, 248, 242); padding: 0.5em;"><code>Input:
map = 
[[<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>],
 [<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>],
 [<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">0</span>],
 [<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">1</span>],
 [<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>]
]
start = [<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">4</span>]
end = [<span style="color: rgb(245, 171, 53);">4</span>,<span style="color: rgb(245, 171, 53);">4</span>]
Output:
<span style="color: rgb(245, 171, 53);">true</span></code></pre></div></pre></div></div>