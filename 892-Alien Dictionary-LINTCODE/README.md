<h2><a href="https://www.lintcode.com/problem/892/description">892 · Alien Dictionary</a></h2>


<h3>HARD</h3>
<hr>

<div data-h5="false" class="problem-description-content-3Li9u4xPVfRLi_Nzzm3e_n"><div data-h5="false" class="content-wrapper-32rgvmtTEZlJxhYe-SXar4"><div class="sub-title-3tQamyyYH5-VXCEHKrzgsd with-action-3ISUSOCo8G5-PfWWWyKDb9">Description</div><div class="react-markdown react-markdown-2P3YjvgELb5tvqGDu8Rkkt"><p>There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of <strong>non-empty</strong> words from the dictionary, where words are <strong>sorted lexicographically by the rules of this new language</strong>. Derive the order of letters in this language.</p></div>
    
<li>You may assume all letters are in lowercase.</li>
<li>The dictionary is invalid, if string a is prefix of string b and b is appear before a.</li>
<li>If the order is invalid, return an empty string.</li>
<li>There may be multiple valid order of letters, return the smallest in normal lexicographical order.</li>
<li>The letters in <strong>one</strong> string are of the same rank by default and are sorted in Human dictionary order.</li>

<div class="react-markdown react-markdown-2P3YjvgELb5tvqGDu8Rkkt"><p><strong>Example 1:</strong></p>
<pre><div class="markdown-thumbnail-wrapper" style="height: auto; max-height: unset;"><pre style="display: block; overflow-x: auto; background: rgb(43, 43, 43); color: rgb(248, 248, 242); padding: 0.5em;"><code><span style="color: rgb(220, 198, 224);">Input</span>：["wrt","wrf","er","ett","rftt"]
Output："wertf"
Explanation：
<span style="color: rgb(220, 198, 224);">from</span> "wrt"<span style="color: rgb(220, 198, 224);">and</span>"wrf" ,we can <span style="color: rgb(220, 198, 224);">get</span> <span style="color: rgb(171, 227, 56);">'t'</span>&lt;<span style="color: rgb(171, 227, 56);">'f'</span>
<span style="color: rgb(220, 198, 224);">from</span> "wrt"<span style="color: rgb(220, 198, 224);">and</span>"er" ,we can <span style="color: rgb(220, 198, 224);">get</span> <span style="color: rgb(171, 227, 56);">'w'</span>&lt;<span style="color: rgb(171, 227, 56);">'e'</span>
<span style="color: rgb(220, 198, 224);">from</span> "er"<span style="color: rgb(220, 198, 224);">and</span>"ett" ,we can <span style="color: rgb(220, 198, 224);">get</span> <span style="color: rgb(171, 227, 56);">'r'</span>&lt;<span style="color: rgb(171, 227, 56);">'t'</span>
<span style="color: rgb(220, 198, 224);">from</span> "ett"<span style="color: rgb(220, 198, 224);">and</span>"rftt" ,we can <span style="color: rgb(220, 198, 224);">get</span> <span style="color: rgb(171, 227, 56);">'e'</span>&lt;<span style="color: rgb(171, 227, 56);">'r'</span>
So <span style="color: rgb(220, 198, 224);">return</span> "wertf"
</code></pre></div></pre>
<p><strong>Example 2:</strong></p>
<pre><div class="markdown-thumbnail-wrapper" style="height: auto; max-height: unset;"><pre style="display: block; overflow-x: auto; background: rgb(43, 43, 43); color: rgb(248, 248, 242); padding: 0.5em;"><code><span style="color: rgb(220, 198, 224);">Input</span>：["z","x"]
Output："zx"
Explanation：
<span style="color: rgb(220, 198, 224);">from</span> "z" <span style="color: rgb(220, 198, 224);">and</span> "x"，we can <span style="color: rgb(220, 198, 224);">get</span> <span style="color: rgb(171, 227, 56);">'z'</span> &lt; <span style="color: rgb(171, 227, 56);">'x'</span>
So <span style="color: rgb(220, 198, 224);">return</span> "zx"</code></pre></div></pre></div></div></div>

